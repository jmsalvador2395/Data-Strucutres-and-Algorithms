#include <thread>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>


int main(int argc, char** argv){
	int arr[100];
	std::srand(std::time(NULL));
	std::ifstream f;
	f.open("out.txt");
	int n;
	for(int i=0; i<100; i++){
		f>>n;
		printf("%d\n", n);
	}
	f.close();
	return 0;
}

