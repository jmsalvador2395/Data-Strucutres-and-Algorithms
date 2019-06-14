#ifndef _HEAP_H_
#define _HEAP_H_
template<typename T>
class Heap{
	public:
		Heap();
		Heap(int size);
		~Heap();
		static T parent(int i);
		static T left(int i);
		static T right(int i);
		void max_heapify(int i);
		void build_max_heap();
		void heapsort_max();
		void heapsort_min();
	private:
		int length, size;
		T *arr;
		
};
#endif

template<typename T>
Heap<T>::Heap(){
	arr=new T[31];
	length=31;
}

template<typename T>
Heap<T>::Heap(int length){
	arr=new T[length];
	size=0;
}

template<typename T>
Heap<T>::~Heap(){
	delete[] arr;
}


