#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

template<typename T>
void print_int_heap(Heap<T> heap){
	
}
int main(int argc, char **argv){
	int arr[10];
	for(int i=0; i<10; i++)
		//arr[9-i]=i;
		arr[i]=i;
	Heap<int> heap(arr, 10, 10);

	for(int i=0; i<10;i++)
		printf("%d ",heap[i]);
	printf("\n");
	heap.build_max_heap();
	//heap.heapsort();
	//heap.build_min_heap();
	//heap.reverse_heapsort();
	for(int i=0; i<heap.get_size(); i++)
		printf("%d ", heap[i]);
	printf("\n");
	
	//heap.max_heapify(0);
	int tmp=heap.extract_max();
	for(int i=0; i<9; i++)
		printf("%d ", heap[i]);
	printf("\n");
	return 0;
}
