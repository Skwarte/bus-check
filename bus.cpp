//TODO: add :help function, add funtionality to add people onto the bus
//add function to see how many people are in the bus at the time
//add func to see how many people would be in the bus at a certain stop;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "bus.h"

int main() {
	Bus bus;

	cout << "How many seats are there on the bus?  " << endl << "➜  "; 
	cin >> bus.seats;


	cout << "\nHow many stops are there?  " << endl << "➜  "; 
	cin >> bus.stops;

	int * arr = new int[bus.stops];
	for(int i = 0; i < bus.stops; i++) {
		arr[i] = 0;
	}	

		userChoice(bus, arr);
}

void print(Bus bus, int * arr) {
	cout << "\n\nThese are the current statistics for each stop: " << endl;
	for(int i = 0; i < bus.stops; i++) {
		cout << "Stop " << i+1 << " has " << arr[i] << " passengers and currently has " << bus.seats-arr[i] << " open seats left." << endl;	
	}
}

void userChoice(Bus bus, int * arr) {
	cout << "\nWhat would you like to do? You may either: " << endl << endl << "[A]dd passenger" << endl << endl << "[C]heck Availibility" << endl << endl << "[E]xit" << endl << endl; 
		char ans; //Stores the answer of the User.
		while(1) {
			cout << "➜  ";
			cin >> ans; 
			if(ans == 'C' || ans == 'c') {
				print(bus, arr);	     
			} else if(ans == 'A' || ans == 'a') {
				//go to funct that will add passenger
			} else if(ans == 'E' || ans == 'e') {
				break;
			} else {
				cout << "\nPlease try again. Enter 'A' to add a passenger. Enter 'C' to check seat availibility. Enter 'E' to Exit. " << endl << endl;
			}	
		}
}	
