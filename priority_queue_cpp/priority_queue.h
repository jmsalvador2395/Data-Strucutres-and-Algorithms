#include "queue_container.h"

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
template<typename T>
class PriorityQueue{
	public:
		PriorityQueue();
		PriorityQueue(int length);
		~PriorityQueue();
		int get_size();
		T max();
		T min();
		T extract_max();
		T extract_min();

	private:
		class QueueContainer{
			public:
				QueueContainer(int key, T value);
				const bool operator<(const QueueContainer& other);
				const bool operator>(const QueueContainer& other);
				const bool operator==(const QueueContainer& other);
				const int get_key();
				const T get_value();
				
			private:
				int key;
				T value;
		};

		int parent(int i);
		int left(int i);
		int right(int i);
		void max_heapify(int i);
		void min_heapify(int i);
		void build_max_heap();
		void build_min_heap();
		
		QueueContainer* heap;
		int heap_size, heap_length;

};
#endif

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
PriorityQueue<T>::PriorityQueue(){
	this->heap_size=0;
	this->heap_length=10;
	heap=new QueueContainer[heap_length];
}

