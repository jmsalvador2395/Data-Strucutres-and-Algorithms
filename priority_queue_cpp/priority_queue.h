#include "heap.h"

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
template<typename T>
class PriorityQueue{
	public:
		PriorityQueue();
		PriorityQueue(int length);

		~PriorityQueue();
	private:
		template<typename T>
		class QueueContainer{
			public:
				QueueContainer();
				QueueContainer(int key, T value);
				~QueueContainer();
				operator<(QueueContainer<T> other);
				operator>(QueueContainer<T> other);
				operator==(QueueContainer<T> other);
				int get_key();
				T get_value();
				
			private:
				int key;
				T value;
		};
		Heap<QueueContainer<T>> heap;

};
#endif
