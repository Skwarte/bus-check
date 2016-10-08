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
			addPassenger(bus, arr);				
		} else if(ans == 'E' || ans == 'e') {
			break;
		} else {
			cout << "\nPlease try again. Enter 'A' to add a passenger. Enter 'C' to check seat availibility. Enter 'E' to Exit. " << endl << endl;
		}	
	}
}	
void addPassenger(Bus bus, int * arr) {
	Passenger passenger;
	cout << "Where is the first stop?" << endl << "➜  ";
	cin >> passenger.pickup; 
	cout << "Where is the final stop?" << endl << "➜  ";
	cin >> passenger.destination;

	int validStops = 1; // if the seats picked are valid this will be a 1. If not, it will be a 0; 

	if(passenger.pickup == passenger.destination || passenger.destination < passenger.pickup || passenger.pickup < 0 || passenger.destination > bus.stops) {

		validStops = 0;

		do {
			cout << "Please enter a valid first and final stop" << endl;
			cout << "First stop?" << endl << "➜  ";
			cin >> passenger.pickup; 
			cout << "Final stop?" << endl << "➜  ";
			cin >> passenger.destination;
			if(passenger.pickup == passenger.destination || passenger.destination < passenger.pickup || passenger.pickup < 0 || passenger.destination > bus.stops) {
				validStops = 0;
			} else {
				validStops = 1;
			}
		}while(validStops == 0);

	}
	int enoughSpace = 1; //if there is enough space, this will stay as 1; if not it will be a 0;
	for(int i = passenger.pickup; i < passenger.destination; i++) {
		if(arr[i]+1 > bus.seats) {
			enoughSpace = 0;
		}
	}

	int saved = 1;
	if(enoughSpace == 1) {
		for(int i = passenger.pickup; i <= passenger.destination; i++) {
			arr[i] += 1;	
		}
	} else {
		saved = 0;
		cout << "There is not enough space on the bus at the moment. Press [C] to check the bus's seat availibility." << endl;
	}
	if(saved == 1) {
		cout << "Your information has been sucessfully saved" << endl << endl;;
	}
}
