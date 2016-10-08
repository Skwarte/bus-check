using namespace std;
typedef struct Bus {
    int seats;
    int stops;
} Bus;

typedef struct Person {
    char * name;
    int pickup;
	int destination;
} Person;


void print(Bus bus, int * arr);
void userChoice(Bus bus, int * arr);
void setBusPopulation();
void getBusPopulation();

