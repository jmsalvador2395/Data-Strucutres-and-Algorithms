#ifndef _HEAP_H_
#define _HEAP_H_
template<typename T>
class Heap{
	public:
		Heap(); //line 26
		Heap(int length); //line 34
		Heap(T *arr, int size, int length); //line 40
		~Heap(); //line 53
		T &operator[](int index); //line 58
		int parent(int i); //line 65
		int left(int i); //line 72
		int right(int i); //line 79
		void max_heapify(int i); //line
		void min_heapify(int i); //line
		void build_max_heap(); //line
		void build_min_heap(); //line
		void heapsort(); //line
		void reverse_heapsort(); //line
		T max();
		T extract_max();
	private:
		int length, size;
		T *arr;
		
};
#endif

//i just felt like makeing a defaut constructor
template<typename T>
Heap<T>::Heap(){
	this->arr=new T[31];
	this->length=31;
	this->size=0;
}

//initialize with a specific array size
template<typename T>
Heap<T>::Heap(int length){
	arr=new T[length];
	size=0;
}

//takes an array to use as a heap
template<typename T>
Heap<T>::Heap(T *arr, int size, int length){
	this->arr=new T[size];
	for(int i=0; i<size; i++)
		this->arr[i]=arr[i];
	
	this->size=size;
	this->length=length;
	
}

//delete the array
template<typename T>
Heap<T>::~Heap(){
	delete[] arr;
}

//give direct access to the internal array
template<typename T>
T &Heap<T>::operator[](int index){
	return arr[index];
}

//returns parent of a given index
template<typename T>
int Heap<T>::parent(int i){
	return i/2;
}

//returns left child of a given index
//I use i*2+1 because the book's index starts at 1 (originally i*2)
template<typename T>
int Heap<T>::left(int i){
	return i*2+1;
}

//returns right child index of an input index
//I use i*2+2 because the book's index starts at 1 (originally i*2+1)
template<typename T>
int Heap<T>::right(int i){
	return i*2+2;
}

//indeces are slightly different from the book
template<typename T>
void Heap<T>::max_heapify(int i){
	int largest;
	int l=this->left(i);
	int r=this->right(i);

	//book calls for l<=size 
	if(l<this->size && this->arr[l]>arr[i]){
		largest=l;
	}
	else{
		largest=i;
	}

	//book calls for r<=size
	if(r<this->size && arr[r]>arr[largest]){
		largest=r;
	}

	if(largest!=i){
		T temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		this->max_heapify(largest);
	}
	else{
		return;
	}
}

template<typename T>
void Heap<T>::min_heapify(int i){
	int smallest;
	int l=this->left(i);
	int r=this->right(i);

	//book calls for l<=size 
	if(l<this->size && this->arr[l]<arr[i]){
		smallest=l;
	}
	else{
		smallest=i;
	}

	//book calls for r<=size
	if(r<this->size && arr[r]<arr[smallest]){
		smallest=r;
	}

	if(smallest!=i){
		T temp=arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=temp;
		this->min_heapify(smallest);
	}
	else{
		return;
	}

}
//indeces are different from the book because the book's arrays start at index 1 and not 0
template<typename T>
void Heap<T>::build_max_heap(){
	this->size=this->length;

	for(int i=length/2; i>=0; i--)
		this->max_heapify(i);
}

template<typename T>
void Heap<T>::build_min_heap(){
	this->size=this->length;

	for(int i=length/2; i>=0; i--)
		this->min_heapify(i);
}

template<typename T>
void Heap<T>::heapsort(){
	this->build_max_heap();
	
	//book asks to loop until you get to index 2 but in our case it's index 1
	for(int i=this->length-1; i>=1; i--){
		T temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		this->size--;
		this->max_heapify(0);
	}
}

template<typename T>
void Heap<T>::reverse_heapsort(){
	this->build_min_heap();

	for(int i=this->length-1; i>=1; i--){
		T temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		this->size--;
		this->min_heapify(0);
	}
}

//only use this after running max_heapify()
template<typename T>
T Heap<T>::max(){
	return this->arr[0];
}

//returns the largest value and deletes it from the heap. returns NULL if the heap is empty
template<typename T>
T Heap<T>::extract_max(){
	if(this->size<1)
		return NULL;
	int max=arr[0];
	arr[0]=this->arr[size-1];
	this->size--;
	return max;
}
