#include <thread>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>


int main(int argc, char** argv){
	int total=1000000;
	std::srand(std::time(NULL));
	std::ofstream f;
	f.open("out.txt");
	for(int i=0; i<total; i++)
		f<<std::rand()%total<<"\n";
	f.close();
	return 0;
}

