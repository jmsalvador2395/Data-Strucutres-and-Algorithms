#include <stdio.h>
#include <string>
#include <sstream>
#include <exception>

#define MAX_INT_SIZE 0xFFFF

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
template<typename T>
class PriorityQueue{
	public:
		PriorityQueue(); //sets a default heap size of 10
		PriorityQueue(int length);  //set your own heap size with default as a max priority queue
		PriorityQueue(int length, char queue_type); //explicitly set heap size and queue type. 'M' for max and 'm' for min
		~PriorityQueue();
		int get_size();
		T peek_value(); //Heap-Max (or min) implemented in the book 
		int peek_key(); // like peek_value but grabs the key instead
		T pop(); //Heap-Extract-Max (or min) implemented the book
		void insert(int key, T value); //Max-Heap-Insert (or min) implemented in the book
		std::string str();

	private:
		class QueueContainer{
			public:
				QueueContainer();
				QueueContainer(int key, T value);
				bool operator<( QueueContainer& other);
				bool operator>( QueueContainer& other);
				void operator=( QueueContainer& other);
				void operator=( QueueContainer* other);
				bool operator==( QueueContainer& other);
				int get_key();
				T get_value();
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
		void build_min_heap();
		void maxq_increase_key(int i, int key);
		void minq_decrease_key(int i, int key);

		QueueContainer* heap;
		int heap_size, heap_length;
		char queue_type; //M for max, m for min

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
bool PriorityQueue<T>::QueueContainer::operator<(QueueContainer& other){
	return (this->key < other.key);
}

template<typename T>
bool PriorityQueue<T>::QueueContainer::operator>(QueueContainer& other){
	return (this->key > other.key);
}

template<typename T>
void PriorityQueue<T>::QueueContainer::operator=(QueueContainer& other){
	this->key=other.get_key();
	this->value=other.get_value();
}

template<typename T>
void PriorityQueue<T>::QueueContainer::operator=(QueueContainer* other){
	this->key=other->get_key();
	this->value=other->get_value();
}

template<typename T>
bool PriorityQueue<T>::QueueContainer::operator==(QueueContainer& other){
	return (this->key == other.key);
}

template<typename T>
int PriorityQueue<T>::QueueContainer::get_key(){
	return this->key;
}

template<typename T>
T PriorityQueue<T>::QueueContainer::get_value(){
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
	this->queue_type='M';
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int length){
	this->heap_size=0;
	this->heap_length=length;
	heap=new QueueContainer[length];
	this->queue_type='M';
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int length, char queue_type){
	this->heap_size=0;
	this->heap_length=length;
	heap=new QueueContainer[length];
	this->queue_type=queue_type;
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
T PriorityQueue<T>::peek_value(){
	try{
		if(this->heap_size==0)
			throw "Error from function peek(): queue is empty";
	}
	catch(const char* e){
		printf("%s\n", e);
	}
	return heap[0].get_value();
}

template<typename T>
int PriorityQueue<T>::peek_key(){
	try{
		if(this->heap_size==0)
			throw "Error from function peek(): queue is empty";
	}
	catch(const char* e){
		printf("%s\n", e);
	}
	return heap[0].get_key();

}

template<typename T>
T PriorityQueue<T>::pop(){
	T max=heap[0].get_value();
	heap[0]=heap[this->heap_size-1];
	this->heap_size--;
	if(this->queue_type=='M')
		this->max_heapify(0);
	else
		this->min_heapify(0);
	return max;
}
//book says to insert at heap_size but their indeces also start at 1 so we instead insert at heap_size-1
template<typename T>
void PriorityQueue<T>::insert(int key, T value){
	try{
		if(heap_size+1>heap_length){
			throw "Error from function insert(): heap overflow"; //will write code to double the heap size in the future
		}
	}
	catch(const char* e){
		printf("%s\n", e);
	}
	this->heap_size++;
	if(this->queue_type=='M'){
		heap[this->heap_size-1].set_key(-1);
		heap[this->heap_size-1].set_value(value);
		this->maxq_increase_key(this->heap_size-1, key);
	}
	else{ //goes here if it's a min queue
		heap[this->heap_size-1].set_key(MAX_INT_SIZE);
		heap[this->heap_size-1].set_value(value);
		this->minq_decrease_key(this->heap_size-1, key);
	}
}

//only works on basic data types
template<typename T>
std::string PriorityQueue<T>::str(){
	std::stringstream ss;
	ss << "[ ";
	for(int i=0; i<this->heap_size; i++){
		ss << "(" << heap[i].get_key() << ", " << heap[i].get_value() << ") ";
	}
	ss << "]";
	return ss.str();
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
	if(l<this->heap_size && this->heap[l]>heap[i]){
		largest=l;
	}
	else{
		largest=i;
	}
	
	//book calls for r<=heap_size
	if(r<this->heap_size && heap[r]>heap[largest]){
		largest=r;
	}

	if(largest!=i){
		QueueContainer temp=heap[i];
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

	//book calls for l<=heap_size 
	if(l<this->heap_size && this->heap[l]<heap[i]){
		smallest=l;
	}
	else{
		smallest=i;
	}

	//book calls for r<=heap_size
	if(r<this->heap_size && heap[r]<heap[smallest]){
		smallest=r;
	}

	if(smallest!=i){
		QueueContainer temp=heap[i];
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

//updates the key of the node at index i and percolates the node upwards to correct the max heap
template<typename T>
void PriorityQueue<T>::maxq_increase_key(int i, int key){
	try{
		if(i<=heap[i].get_key())
			throw "Error from function maxq_increase_key(): key is not bigger than the original";
	}
	catch(const char* e){
		printf("%s\n", e);
	}

	heap[i].set_key(key);
	while(i>=0 && heap[this->parent(i)]<heap[i]){
		QueueContainer temp=heap[i];
		heap[i]=heap[this->parent(i)];
		this->heap[parent(i)]=temp;
		i=this->parent(i);
	}
}

template<typename T>
void PriorityQueue<T>::minq_decrease_key(int i, int key){
	try{
		if(i>=heap[i].get_key())
			throw "Error from function maxq_increase_key(): key is not smaller than the original";
	}
	catch(const char* e){
		printf("%s\n", e);
	}

	heap[i].set_key(key);
	while(i>=0 && heap[this->parent(i)]>heap[i]){
		QueueContainer temp=heap[i];
		heap[i]=heap[this->parent(i)];
		this->heap[parent(i)]=temp;
		i=this->parent(i);
	}
}

