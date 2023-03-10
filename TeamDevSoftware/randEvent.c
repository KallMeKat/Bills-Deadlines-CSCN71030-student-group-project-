#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Struct for the linked list of random events
struct Encounter {
	char* description;
	struct Enounter* next;
	//Possibly add other values that come with the encounter struct that affect your player struct, such as your money, morale etc.
};

// Function to generate the random events number (1-6)
int random_number() {
	srand(time(NULL));
	return (rand() % 6) + 1;
}

//Function to create a new event node
struct Encounter* createEncounter(char* description) {
	struct Encounter* newEncounter = (struct Event*)malloc(sizeof(struct Encounter));
	newEncounter->description = description;
	newEncounter->next = NULL;
	return newEncounter;
}

