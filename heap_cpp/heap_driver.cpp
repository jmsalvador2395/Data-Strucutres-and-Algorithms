#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char **argv){
	int arr[10];
	for(int i=0; i<10; i++)
		arr[9-i]=i;
		//arr[i]=i;
	Heap<int> heap(arr, 10, 10);

	for(int i=0; i<10;i++)
		printf("%d ",heap[i]);
	printf("\n");
	heap.build_max_heap();
	heap.heapsort();
	for(int i=0; i<10; i++)
		printf("%d ", heap[i]);
	printf("\n");
	/*
	heap.max_heapify(0);
	for(int i=0; i<10; i++)
		printf("%d ", heap[i]);
	printf("\n");
	*/
	return 0;
}
