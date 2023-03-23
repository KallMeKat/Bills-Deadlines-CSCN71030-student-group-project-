
#ifndef RAND_EVENT_H_
#define RAND_EVENT_H_

//Struct for the linked list of random events
struct Encounter {
	int id;
	char* description[100];
	struct Enounter* next;
	//Add other values that come with the encounter struct that affect your player struct, such as your money, morale etc.
};


struct Encounter* createEncounter(int id, char desc[]);
struct Encounter* selectEncounter(struct Encounter* head);
int random_number();

#endif