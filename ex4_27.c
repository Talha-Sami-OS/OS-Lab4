#include <pthread.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <Windows.h>

int shared_data[10000];

void *fibonacci_thread(void* params);
void parent(int* numbers);

 int main() {

	int numbers = 0; //user input.

	pthread_t child; // create thread
	pthread_attr_t attr; 
	pthread_attr_init(&attr); 

	parent(&numbers); // get user input then start separate thread.
	pthread_create(&child, &attr, fibonacci_thread, (void*) &numbers); //starts fibonacci thread
	pthread_join(child, NULL); //waits for thread to finish

	//output to command prompt after thread finishes.
	for(int i = 0; i <= shared_data[i]; i++) {
		printf("%d",shared_data[i]);
	}

	return 0;
 }

void *fibonacci_thread(void* params) {
	
	int fib0 = 0, fib1 = 1, next = 0;
	int *pointer;
	pointer = (int*) params;
	int total = *pointer;
	
	for (int i = 0 ; i < total; i++ ) {
      if ( i <= 1 )
         next = i;
      else {
         next = fib0 + fib1;
         fib0 = fib1;
         fib1 = next;
      }
	  next = shared_data[i]; //store to shared_data array
	}
	//pthread_exit(0);
	return NULL;
}

void parent(int* numbers) {
	std::cout<<"Enter in a number to generate the Fibonacci sequence: ";
	std::cin>>*numbers;

	while(isdigit(*numbers) != true) {
		std::cout<<"Invalid character, please enter in a number: ";
		std::cin>>*numbers;
	}

	return;
}