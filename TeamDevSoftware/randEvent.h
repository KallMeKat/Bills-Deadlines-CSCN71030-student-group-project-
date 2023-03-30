
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
void handleJobEvent(struct Encounter* event, PlayerStats playerStats[]);
void handleEvent(struct Encounter* event, PlayerStats playerStats[]);
void eventOne(PlayerStats playerStats[]);
void eventTwo(PlayerStats playerStats[]);
void eventThree(PlayerStats playerStats[]);
void eventFour(PlayerStats playerStats[]);
void eventFive(PlayerStats playerStats[]);
void eventSix(PlayerStats playerStats[]);


#endif