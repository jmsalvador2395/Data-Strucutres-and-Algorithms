#ifndef _QUEUE_CONTAINER_H_
#define _QUEUE_CONTAINER_H_
template<typename T>
class QueueContainer{
	public:
		QueueContainer(int key, T value);
		const bool operator<(QueueContainer& other);
		const bool operator>(QueueContainer& other);
		const bool operator==(QueueContainer& other);
		int get_key();
		T get_value();
		void set_key(int i);
		void set_value(T& value);
	private:
		int key;
		T value;
};
#endif

