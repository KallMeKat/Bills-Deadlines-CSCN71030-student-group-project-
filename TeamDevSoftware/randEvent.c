#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randEvent.h"

// Function to generate the random events number (1-6)
int random_number() {
	srand(time(NULL));
	return (rand() % 3) + 1;
}

//Function to create a new event node
struct Encounter* createEncounter(int id, char desc[]) {
	struct Encounter* newEncounter = (struct Encounter*)malloc(sizeof(struct Encounter));
	newEncounter->id = id;
	strcpy(newEncounter->description, desc);
	newEncounter->next = NULL;
	return newEncounter;
}

//Function that will select a random event using the random_number function
struct Encounter* selectEncounter(struct Encounter* head) {
	int eventNumber = random_number();
	struct Encounter* current = head;
	while (current != NULL) {
		if (current->id == eventNumber) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

