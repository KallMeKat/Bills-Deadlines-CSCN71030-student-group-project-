
#ifndef RAND_EVENT_H_
#define RAND_EVENT_H_
#include "PlayerStats.h"


//Struct for the linked list of random events
struct Encounter {
	int id;
	char description[100];
	struct Encounter* next;
	//Add other values that come with the encounter struct that affect your player struct, such as your money, morale etc.
};


struct Encounter* createEncounter(int id, char desc[]);
struct Encounter* selectEncounter(struct Encounter* head);
int random_number();
struct Encounter* initializeEncounters();
struct Encounter* initializeJobEncounters();
void handleJobEvent(struct Encounter* event, PlayerStats** player);
void handleEvent(struct Encounter* event, PlayerStats** player);
void eventOne(PlayerStats* player);
void eventTwo(PlayerStats* player);
void eventThree(PlayerStats* player);
void eventFour(PlayerStats* player);
void eventFive(PlayerStats* player);
void eventSix(PlayerStats* player);


#endif