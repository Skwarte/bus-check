using namespace std;
typedef struct Bus {
    int seats;
    int stops;
} Bus;

typedef struct Passenger {
    int pickup;
	int destination;
} Passenger;


void print(Bus bus, int * arr);
void userChoice(Bus bus, int * arr);
void addPassenger(Bus bus, int * arr);
void setBusPopulation();
void getBusPopulation();

