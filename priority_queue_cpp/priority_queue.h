#include <string>
#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
template<typename T>
class PriorityQueue{
	public:
		PriorityQueue(); //sets a default heapay size of 10
		PriorityQueue(int length);  //set your own heapay size with default as a max priority queue
		PriorityQueue(int length, int queue_type);
		~PriorityQueue();
		int get_size();
		T& peek(); //Heap-Max (or min) implemented in the book 
		T& dequeue(); //Heap-Extract-Max (or min) implemented the book
		void insert(int key, T value); //Max-Heap-Insert (or min) implemented in the book

	private:
		class QueueContainer{
			public:
				QueueContainer();
				QueueContainer(int key, T value);
				const bool operator<(const QueueContainer& other);
				const bool operator>(const QueueContainer& other);
				void operator=(const QueueContainer& other);
				const bool operator==(const QueueContainer& other);
				const int get_key();
				const T get_value();
				void set_key(int i);
				void set_value(T val);
				
			private:
				int key;
				int max_or_min; //0 for max, 1 for min
				T value;
		};

		int parent(int i);
		int left(int i);
		int right(int i);
		void max_heapify(int i); 
		void min_heapify(int i);
		void build_max_heap();
		void build_min_heap(); void maxq_increase_key(int i, int key);
		void minq_decrease_key(int i, int key);

		QueueContainer* heap;
		int heap_size, heap_length;

};
#endif

//this is just for initialization of the array
template<typename T>
PriorityQueue<T>::QueueContainer::QueueContainer(){}

template<typename T>
PriorityQueue<T>::QueueContainer::QueueContainer(int key, T value){
	this->key=key;
	this->value=value;
}

template<typename T>
const bool PriorityQueue<T>::QueueContainer::operator<(const QueueContainer& other){
	return (this->key > other.key);
}

template<typename T>
const bool PriorityQueue<T>::QueueContainer::operator>(const QueueContainer& other){
	return (this->key < other.key);
}

template<typename T>
void PriorityQueue<T>::QueueContainer::operator=(const QueueContainer& other){
	this->key=other.get_key();
	this->value=other.get_value();
}

template<typename T>
const bool PriorityQueue<T>::QueueContainer::operator==(const QueueContainer& other){
	return (this->key == other.key);
}

template<typename T>
const int PriorityQueue<T>::QueueContainer::get_key(){
	return this->key;
}

template<typename T>
const T PriorityQueue<T>::QueueContainer::get_value(){
	return this->value;
}

template<typename T>
void PriorityQueue<T>::QueueContainer::set_key(int i){
	this->key=i;
}

template<typename T>
void PriorityQueue<T>::QueueContainer::set_value(T val){
	this->value=val;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(){
	this->heap_size=0;
	this->heap_length=10;
	heap=new QueueContainer[this->heap_length];
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int length){
	this->heap_size=0;
	this->heap_length=length;
	heap=new QueueContainer[length];
}

template<typename T>
PriorityQueue<T>::~PriorityQueue(){
	delete[] this->heap;
}

template<typename T>
int PriorityQueue<T>::get_size(){
	return this->heap_size;
}

template<typename T>
T& PriorityQueue<T>::peek(){
	if(this->heap_size==0)
		throw "queue is empty";
	return heap[0];
}

//book says to insert at heap_size but their indeces also start at 1 so we instead insert at heap_size-1
template<typename T>
void PriorityQueue<T>::insert(int key, T value){
	if(heap_size+1>heap_length)
		throw "heap overflow"; //will write code to double the heap size in the future
	this->heap_size++;
	heap[this->heap_size-1].set_key(-1);
	heap[this->heap_size-1].set_value(value);
	this->maxq_increase_key(this->heap_size-1, key);
}

template<typename T>
int PriorityQueue<T>::parent(int i){
	return i/2;
}

template<typename T>
int PriorityQueue<T>::left(int i){
	return i*2+1;
}

template<typename T>
int PriorityQueue<T>::right(int i){
	return i*2+2;
}

template<typename T>
void PriorityQueue<T>::max_heapify(int i){
	int largest;
	int l=this->left(i);
	int r=this->right(i);

	//book calls for l<=size 
	if(l<this->size && this->heap[l]>heap[i]){
		largest=l;
	}
	else{
		largest=i;
	}

	//book calls for r<=size
	if(r<this->size && heap[r]>heap[largest]){
		largest=r;
	}

	if(largest!=i){
		T temp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=temp;
		this->max_heapify(largest);
	}
	else{
		return;
	}

}

template<typename T>
void PriorityQueue<T>::min_heapify(int i){
	int smallest;
	int l=this->left(i);
	int r=this->right(i);

	//book calls for l<=size 
	if(l<this->size && this->heap[l]<heap[i]){
		smallest=l;
	}
	else{
		smallest=i;
	}

	//book calls for r<=size
	if(r<this->size && heap[r]<heap[smallest]){
		smallest=r;
	}

	if(smallest!=i){
		T temp=heap[i];
		heap[i]=heap[smallest];
		heap[smallest]=temp;
		this->min_heapify(smallest);
	}
	else{
		return;
	}

}

template<typename T>
void PriorityQueue<T>::build_max_heap(){
	this->heap_size=this->heap_length;
	for(int i=heap_length/2; i>=0; i--)
		this->max_heapify(i);
}

template<typename T>
void PriorityQueue<T>::build_min_heap(){
	this->heap_size=this->heap_length;
	for(int i=heap_length/2; i>=0; i--)
		this->min_heapify(i);
}

template<typename T>
void PriorityQueue<T>::maxq_increase_key(int i, int key){
	if(heap[i].get_key()<=i)
		throw "key is not bigger than the original";
	heap[i].set_key(key);
	while(i>=0 && heap[this->parent(i)]>heap[i]){
		QueueContainer temp=heap[i];
		heap[i]=heap[this->parent(i)];
		this->heap[parent(i)]=temp;
		i=this->parent(i);
	}
}
