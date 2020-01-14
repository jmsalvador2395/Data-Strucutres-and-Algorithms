#include <thread>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <mutex>

int part(int arr[], int l, int r){
	int pivot=arr[r];
	int i=l-1;
	for(int j=l; j<r; j++){
		if(arr[j] <= pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			//printf("%d\n", j);
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}

void quicksort(int arr[], int l, int r){
	if(l<r){
		int pt=part(arr, l, r);

		quicksort(arr, l, pt-1);
		quicksort(arr, pt+1, r);
	}
	return;
}

void multiquicksort(int arr[], int l, int r, int corecount){
	std::thread t1;
	if(l<r){
		
		int pt=part(arr, l, r);
		
		if(corecount>5){
			t1=std::thread(multiquicksort, std::ref(arr), l, pt-1, corecount-1);
			multiquicksort(arr, pt+1, r, corecount-1);
		}
		else{
			quicksort(arr, l, pt-1);
			quicksort(arr, pt+1, r);
		}
	}
	if(t1.joinable())
		t1.join();
	return;
}

int main(int argc, char** argv){
	int count=1000000;
	int arr[count];
	std::srand(std::time(NULL));
	std::cout<<"Cores:\t" << std::thread::hardware_concurrency() << "\n";
	for(int j=0; j<100000; j++){
		for(int i=0; i<count; i++)
			arr[i]=rand()%count;
		bool a;	
		if(argc>1){
			if(std::string(argv[1])==std::string("-m")){
				multiquicksort(arr, 0, count-1, std::thread::hardware_concurrency());
				a=1;
			}
		}
		else{
			quicksort(arr, 0, count-1);
		}
		/*
		for(int i=0; i<count; i++)
			std::cout<<arr[i]<<"\n";
		*/
		if(a)
			printf("***********************************************************\n");
		else
			printf("-----------------------------------------------------------\n");
	}
	return 0;
}

