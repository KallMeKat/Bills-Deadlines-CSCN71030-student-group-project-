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
	struct Encounter* head = createEncounter(1, "A homeless person pulls a knife on you. What do you do?\n");
	struct Encounter* second = createEncounter(2, "As you are leaving the park, you spot a wallet lying on the ground. What do you do?\n");
	struct Encounter* third = createEncounter(3, "Some random event happens?\n");

	head->next = second;
	second->next = third;
	third->next = NULL;

	return head;
}

struct Encounter* initializeJobEncounters() {
	struct Encounter* head = createEncounter(1, "You catch a shoplifter in the act. What do you do?\n");
	struct Encounter* second = createEncounter(2, "Two customers are fighting over the last TV in the store. What do you do?\n");
	struct Encounter* third = createEncounter(3, "You are working at Walmart when you notice a group of teenagers attempting to steal some electroni\n");

	head->next = second;
	second->next = third;
	third->next = NULL;

	return head;
}


//function for switch case menu

void handleEvent(struct Encounter* event, PlayerStats playerStats[]) {
	switch (event->id) {
	case 1:
		eventOne(playerStats);
		break;
	case 2:
		eventTwo(playerStats);
		break;
	case 3:
		eventThree(playerStats);
		break;
	default:
		printf("Unknown event!\n");
		break;
	}
}

//Job event switch case menu


void handleJobEvent(struct Encounter* event, PlayerStats playerStats[]) {
	switch (event->id) {
	case 1:
		eventFour(playerStats);
		break;
	case 2:
		eventFive(playerStats);
		break;
	case 3:
		eventSix(playerStats);
		break;
	default:
		printf("Unknown event!\n");
		break;
	}
}



//switch cases for the events, allowing you to select how you react to a situation
//player stats affected according to seleted response


/// Events 1-3 are park events
void eventOne(PlayerStats playerStats[]) {

	printf("1. Run away.\n");
	printf("2. Fight back.\n");
	printf("3. Give them some money.\n");


	bool continueProgram = true;
	while (continueProgram) {

		char choice;
		scanf(" %c", &choice);

		switch (choice) {
		case '1':
			printf("\nYou manage to run away, but you lose some energy.\n\n");
			
			decreaseEnergy(2, playerStats);
			printStats(playerStats);

			continueProgram = false;

			break;
		case '2':
			printf("\nYou fight back and manage to get away, but you lose some health and energy.\n\n");

			damagePlayer(4, playerStats); 
			decreaseEnergy(3, playerStats);

			printStats(playerStats);

			continueProgram = false;
			break;

		case '3':
			if (playerStats->cash < 5) {

				printf("\nYou have no cash! He attacks you anyways\n");

				damagePlayer(4, playerStats);
				decreaseEnergy(3, playerStats);

				printStats(playerStats);

			}

			printf("\nYou give the homeless person some money and they leave you alone.\n\n");

			decreaseCASH(5, playerStats);

			continueProgram = false;
			break;
		default:
			printf("\nInvalid choice!\n");
			break;
		}

	}


}

void eventTwo(PlayerStats playerStats[]) {

	printf("1. Pick up the wallet and look for identification to return it.\n");
	printf("2. Pick up the wallet and keep it.\n");
	printf("3. Leave the wallet alone.\n");




	bool continueProgram = true;
	while (continueProgram) {

		char choice;
		scanf(" %c", &choice);

		switch (choice) {
		case '1':
			printf("\nYou pick up the wallet and search for identification. You find a driver's license and return the wallet to its rightful owner, who rewards you with some cash. You feel more charismatic for helping\n\n");
			
			increaseCASH(20, playerStats);

			levelCha(1, playerStats);

			printStats(playerStats);

			
			continueProgram = false;
			break;
		case '2':
			printf("\nYou pick up the wallet and keep it. Inside, you find some cash and a credit card. You decide to keep the cash and discard the wallet. You feel like you have lost charisma\n\n");
			
			increaseCASH(50, playerStats);

			loseCha(1, playerStats);

			printStats(playerStats);

			continueProgram = false;
			break;
		case '3':
			printf("\nYou leave the wallet alone and continue on your way.\n\n");
			continueProgram = false;
			break;

		default: 
			printf("\nInvalid choice!\n\n");
			break;
		}

	}

}


void eventThree(PlayerStats playerStats[]) {

	printf("1. Options one.\n");
	printf("2. Option two.\n");
	printf("3. Option three.\n");


	bool continueProgram = true;
	while (continueProgram) {

		char choice;
		scanf(" %c", &choice);


		switch (choice) {
		case '1':
			printf("\nYou have selected option 1.\n\n");
			//change player stat 

			continueProgram = false;

			break;
		case '2':
			printf("\nYou have selected option 2.\n\n");
			//change player stat

			continueProgram = false;

			break;
		case '3':
			printf("\nYou have selected option 3.\n\n");
			//change player stat

			continueProgram = false;

			break;

		default:
			printf("\nInvalid choice!\n\n");
			break;
		}
	}
}


//Events 4-6 are job events

void eventFour(PlayerStats playerStats[]) {

	printf("1. Try to apprehend them.\n");
	printf("2. Call security.\n");
	printf("3. Let them go.\n");


	bool continueProgram = true;
	while (continueProgram) {

		char choice;
		scanf(" %c", &choice);

		switch (choice) {
		case '1':
			printf("\nYou attempt to apprehend the shoplifter, but they resist and a scuffle ensues. You manage to hold onto them until security arrives, but you sustain some injuries and lose some energy. You gain strength from the fight.\n\n");
			
			damagePlayer(3, playerStats);

			decreaseEnergy(4, playerStats);

			levelStr(1, playerStats);

			printf("\n\nYou get a bonus for your work!\n\n");

			increaseCASH(10, playerStats);

			printStats(playerStats);


			continueProgram = false;

			break;
		case '2':
			printf("\nYou quickly call security and give them a description of the shoplifter. Security apprehends the shoplifter without incident. You feel relieved, but also a little shaken. You feel weak. \n\n");
			//change player stat


			loseStr(1, playerStats);

			printStats(playerStats);


			continueProgram = false;

			break;
		case '3':
			printf("\nYou decide to let the shoplifter go. You feel conflicted about not doing more, but also relieved that nothing more serious happened. You feel like you've gained charisma for handling the situation alone.\n\n");
			//change player stat

			levelCha(1, playerStats);

			printStats(playerStats);


			continueProgram = false;

			break;
		default:
			printf("\nInvalid choice!\n");
			break;
		}
	}
}

void eventFive(PlayerStats playerStats[]) {

	printf("1. Try to intervene and break up the fight.\n");
	printf("2. Call security to handle the situation.\n");
	printf("3. Stay out of it and let them resolve it on their own.\n");


	bool continueProgram = true;
	while (continueProgram) {

		char choice;
		scanf(" %c", &choice);


		switch (choice) {
		case '1':
			printf("\nYou try to intervene and break up the fight, but it escalates and you get injured. You gain strength from the fight. \n\n");

			damagePlayer(3, playerStats);

			decreaseEnergy(4, playerStats);

			levelStr(1, playerStats);

			printStats(playerStats);


			continueProgram = false;

			break;
		case '2':
			printf("\nYou call security to handle the situation, and they manage to calm the customers down and resolve the issue. You feel relieved, but also a little shaken. You feel weak. \n\n");


			loseStr(1, playerStats);

			printStats(playerStats);

			continueProgram = false;

			break;
		case '3':
			printf("\nYou stay out of it and let them resolve it on their own, but the fight continues and damages some store property.\n\n");

			printStats(playerStats);

			continueProgram = false;

			break;
		default:
			printf("\nInvalid choice!\n");
			break;
		}
	}
}

void eventSix(PlayerStats playerStats[]) {

	printf("1. Confront the teenagers and try to stop them.\n");
	printf("2. Alert your supervisor immediately.\n");
	printf("3. Ignore the situation and continue working.\n");


	bool continueProgram = true;
	while (continueProgram) {

		char choice;
		scanf(" %c", &choice);


		switch (choice) {
		case '1':
			printf("\nYou bravely confront the teenagers, but they become aggressive and violent. You manage to escape unharmed, but they get away with the electronics. You feel brave and strong.\n\n");


			levelCha(1, playerStats);

			levelStr(1, playerStats);

			printStats(playerStats);


			continueProgram = false;

			break;
		case '2':
			printf("\nYou quickly alert your supervisor, who calls the police. The teenagers are caught and the stolen merchandise is returned. Your supervisor commends you for your quick thinking. You feel charismatic for resolving the situation on your own.\n\n");

			levelCha(1, playerStats);

			printStats(playerStats);

			continueProgram = false;

			break;
		case '3':
			printf("\nYou decide to ignore the situation and continue working. Later, you find out that the teenagers got away with the electronics and the theft was reported in the news. Your supervisor reprimands you for not taking action. You must pay for their actions. You feel bad for your inaction and lose charisma.\n\n");


			decreaseCASH(20, playerStats);

			loseCha(1, playerStats);

			printStats(playerStats);

			continueProgram = false;

			break;
		default:
			printf("\nInvalid choice!\n");
			break;
		}
	}
}