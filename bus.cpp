#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "bus.h"

int main(){
	Bus bus;

	cout << "How many seats are there on the bus?" << endl; 
	cin >> bus.seats;


	cout << "How many stops are there " << endl; 
	cin >> bus.stops;

	int * arr = new int[bus.stops];
	for(int i = 0; i < bus.stops; i++) {
		arr[i] = 0;
	}	

	print(bus, arr);	     
	//TODO: add :help function, add funtionality to add people onto the bus
	//add function to see how many people are in the bus at the time
	//add func to see how many people would be in the bus at a certain stop; 
}

void print(Bus bus, int * arr) {
	cout << "These are the current statistics for each stop: " << endl;
	for(int i = 0; i < bus.stops; i++) {
		cout << "Stop " << i+1 << " has " << arr[i] << " passengers and currently has " << bus.seats-arr[i] << " open seats left." << endl;	
	}
}
