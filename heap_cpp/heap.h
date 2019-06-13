#ifndef _HEAP_H_
#define _HEAP_H_
class Heap{
	public:
		Heap(int size);
		~Heap();
		template<typename T>
		T parent(int i);
		template<typename T>
		T left(int i);
		template<typename T>
		T right(int i);
		template<typename T>
		void max_heapify(i);
		template<typename T>
		void build_max_heap();
		template<typename T>
		void heapsort_max();
		template<typename T>
		void heapsort_min();
	private:
		int length, size;
		
}
#endif
