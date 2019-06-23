#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "priority_queue.h"

int main(int argc, char** argv){
	PriorityQueue<int> q(20);
	for(int i=0; i<10; i++)
		q.insert(i, i);
	q.insert(20, -5);
	std::cout << q.str() << "\n";

	int x=q.peek_key();
	int y=q.pop();
	printf("%d %d\n", x, y);
	std::cout << q.str() << "\n";

	
	x=q.peek_key(); //should be 9
	y=q.pop(); //should be 9
	printf("%d %d\n", x, y);
	std::cout << q.str() << "\n";

	return 0;
}
