#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char** argv){
	PriorityQueue<int> q(20);
	for(int i=0; i<10; i++)
		q.insert(i, i);
	return 0;
}
