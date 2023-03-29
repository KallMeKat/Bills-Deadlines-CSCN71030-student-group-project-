#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randEvent.h"
#include "PlayerStats.h"

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

//function that will be used to initiliaze the encounters in the actual game
//This one initializes park Encounters
struct Encounter* initializeEncounters() {
	struct Encounter* head = createEncounter(1, "a homeless person pulls a knife on you.");
	struct Encounter* second = createEncounter(2, "you are hit by a car.");
	struct Encounter* third = createEncounter(3, "you find a hundred dollar bill on the ground.");

	head->next = second;
	second->next = third;
	third->next = NULL;

	return head;
}

struct Encounter* initializeJobEncounters() {
	struct Encounter* head = createEncounter(4, "You catch a shoplifter in the act. What do you do?\n");
	struct Encounter* second = createEncounter(5, "Two customers are fighting over the last TV in the store. What do you do?");
	struct Encounter* third = createEncounter(6, "You are working at Walmart when you notice a group of teenagers attempting to steal some electronics. What do you do?");

	head->next = second;
	second->next = third;
	third->next = NULL;

	return head;
}


//function for switch case menu

void handleEvent(struct Encounter* event, PlayerStats** player) {
	switch (event->id) {
	case 1:
		eventOne(&player);
		break;
	case 2:
		eventTwo(player);
		break;
	case 3:
		eventThree(player);
		break;
	default:
		printf("Unknown event!\n");
		break;
	}
}


void handleJobEvent(struct Encounter* event, PlayerStats** player) {
	switch (event->id) {
	case 1:
		eventFour(&player);
		break;
	case 2:
		eventFive(player);
		break;
	case 3:
		eventSix(player);
		break;
	default:
		printf("Unknown event!\n");
		break;
	}
}



//switch cases for the events, allowing you to select how you react to a situation
//player stats affected according to seleted response


/// Events 1-3 are park events
void eventOne(PlayerStats* player) {

	printf("A homeless person pulls a knife on you. What do you do?\n");
	printf("1. Run away.\n");
	printf("2. Fight back.\n");
	printf("3. Give them some money.\n");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("You manage to run away, but you lose some energy.\n");
		decreaseEnergy(2, player);
		break;
	case 2:
		printf("You fight back and manage to get away, but you lose some health and energy.\n");
		damagePlayer(2, player);
		decreaseEnergy(3, player);
		break;
	case 3:
		printf("You give the homeless person some money and they leave you alone.\n");
		//increaseMoney(5, player);
		break;
	default:
		printf("Invalid choice!\n");
		break;
	}
}

void eventTwo(PlayerStats* player) {

	printf("As you are leaving the park, you spot a wallet lying on the ground. What do you do?\n");
	printf("1. Pick up the wallet and look for identification to return it.\n");
	printf("2. Pick up the wallet and keep it.\n");
	printf("3. Leave the wallet alone.\n");

	int choice;
	scanf("%d", &choice);

	if (choice < 1 || choice > 3) {
		printf("Invalid choice!\n");
		return;
	}

	switch (choice) {
	case 1:
		printf("You pick up the wallet and search for identification. You find a driver's license and return the wallet to its rightful owner, who rewards you with some cash.\n");
		//increaseCash(20, player);
		//increaseMorale(20, player);
		break;
	case 2:
		printf("You pick up the wallet and keep it. Inside, you find some cash and a credit card. You decide to keep the cash and discard the wallet.\n");
		//increaseCash(50, player);
		//decreaseMorale(20, player);
		break;
	case 3:
		printf("You leave the wallet alone and continue on your way.\n");
		//decreaseMorale(20, player);
		break;

	}
}


void eventThree(PlayerStats* player) {

	printf("Some random event happens?\n");
	printf("1. Options one.\n");
	printf("2. Option two.\n");
	printf("3. Option three.\n");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("You have selected option 1.\n");
		//change player stat 

		break;
	case 2:
		printf("You have selected option 2.\n");
		//change player stat
		break;
	case 3:
		printf("You have selected option 3.\n");
		//change player stat
		break;
	default:
		printf("Invalid choice!\n");
		break;
	}
}


//Events 4-6 are job events

void eventFour(PlayerStats* player) {

	printf("You catch a shoplifter in the act. What do you do?\n");
	printf("1. Try to apprehend them.\n");
	printf("2. Call security.\n");
	printf("3. Let them go.\n");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("You attempt to apprehend the shoplifter, but they resist and a scuffle ensues. You manage to hold onto them until security arrives, but you sustain some injuries and lose some energy.\n");
		damagePlayer(3, player);
		decreaseEnergy(4, player);
		break;
	case 2:
		printf("You quickly call security and give them a description of the shoplifter. Security apprehends the shoplifter without incident. You feel relieved, but also a little shaken.\n");
		//change player stat
		break;
	case 3:
		printf("You decide to let the shoplifter go. You feel conflicted about not doing more, but also relieved that nothing more serious happened.\n");
		//change player stat
		break;
	default:
		printf("Invalid choice!\n");
		break;
	}
}

void eventFive(PlayerStats* player) {

	printf("Two customers are fighting over the last TV in the store. What do you do?\n");
	printf("1. Try to intervene and break up the fight.\n");
	printf("2. Call security to handle the situation.\n");
	printf("3. Stay out of it and let them resolve it on their own.\n");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("You try to intervene and break up the fight, but it escalates and you get injured.\n");
		//change player stat
		break;
	case 2:
		printf("You call security to handle the situation, and they manage to calm the customers down and resolve the issue.\n");
		//change player stat
		break;
	case 3:
		printf("You stay out of it and let them resolve it on their own, but the fight continues and damages some store property.\n");
		//change player stat
		break;
	default:
		printf("Invalid choice!\n");
		break;
	}
}

void eventSix(PlayerStats* player) {
	printf("You are working at Walmart when you notice a group of teenagers attempting to steal some electronics. What do you do?\n");
	printf("1. Confront the teenagers and try to stop them.\n");
	printf("2. Alert your supervisor immediately.\n");
	printf("3. Ignore the situation and continue working.\n");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("You bravely confront the teenagers, but they become aggressive and violent. You manage to escape unharmed, but they get away with the electronics.\n");
		//change player stat
		break;
	case 2:
		printf("You quickly alert your supervisor, who calls the police. The teenagers are caught and the stolen merchandise is returned. Your supervisor commends you for your quick thinking.\n");
		//change player stat
		break;
	case 3:
		printf("You decide to ignore the situation and continue working. Later, you find out that the teenagers got away with the electronics and the theft was reported in the news. Your supervisor reprimands you for not taking action.\n");
		//change player stat
		break;
	default:
		printf("Invalid choice!\n");
		break;
	}
}