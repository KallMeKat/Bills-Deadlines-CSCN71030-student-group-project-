//#define _CRT_SECURE_NO_WARNINGS
#include "Menus.h"
#include "game.h"
#include "randEvent.h"
#include <stdio.h>
#include <stdbool.h>


///////////////// AREAS ///////////////////


void Apartment(void) {

	printf("\n\n\n\nyou are in apartment loop\n\n\n\n");

	//if day 1 play first message..
	//if day 5 play unique message when sleeping...
	//etc... story events are ifs based on day


	bool continueProgram = true;
	while (continueProgram) {

		char choice = ApartmentMenu();

		switch (choice)
		{
		case '1':
			printf("you go to sleep, you fill energized (plus to next day & energy)");
			//functions:
				//to sleep a refill energy and set day counter foward

				//player.day ++
				//player.energy = 10 (refilled)
			player.day++;
			player.energy = 10;
				


			//if == to final day play final scene

			break;
		case '2':


			printf("you leave your apartment");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}


	//on new day when leaving play school function based off day
	//if day 1...
			//intellgience check
	//if day 2...


}
void Cafe(void) {

	printf("\n\n\n\nyou are in a cafe loop\n\n\n\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = CafeMenu();

		switch (choice)
		{
		case '1':

		if (player.energy == 0)
		{
			printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
			return;
		}
			printf("you go study for some time, feeling a bit tired but understanding the material more");
			//functions:
				
				//player.energy = 5 (decreases)
			decreaseEnergy(1, player);
			levelStat(player.intl);
			    //time + 1 (not a full day gone but a section gone)
			player.time++;
			

			break;
		case '2':


			printf("you leave the cafe");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}

void School(void) {

	printf("\n\n\n\nyou are inside the school\n\n\n\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = SchoolMenu();

		switch (choice)
		{
		case '1':
			if (player.energy == 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;
			}
			printf("you go to your classes incredibly bored about the material but feel a bit more understnading the material");
			//functions:
			
				//player.energy = 5 (decreases)
			decreaseEnergy(1, player);
				// Intelligence increases 
			levelStat(player.intl);
				//time + 1 (not a full day gone but a section gone)
			player.time++;

			break;
		case '2':


			printf("you leave the school");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}

void Park(bool RandomParkEventOccured) {

	printf("\n\n\n\nyou are inside the park\n\n\n\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = ParkMenu();

		switch (choice)
		{
		case '1':
			printf("you go to take a walk in the part feeling much stronger in your legs after the workout");
			//functions:
			if (player.energy == 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;

			}
				//player.energy = 5 (decreases)
				decreaseEnergy(2, player);

				// Strength increases
				levelStat(player.str);
				//time + 1 (not a full day gone but a section gone)
				player.time++;

			break;
		case '2':

			if (!RandomParkEventOccured == true){

				printf("You decided to leave the park. As you are leaving the park ");

			/////////////////Random Event///////////////
			///////////////////////////////////////////
			struct Encounter* head = initializeEncounters();
			struct Encounter* randomEvent = selectEncounter(head);
			printf("%s\n", randomEvent->description);
			handleEvent(randomEvent, &player);
			//////////////////////////////////////////
			//////////////////////////////////////////
		} else 

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}

void Job(void) {

	printf("\n\n\n\nyou are inside your job\n\n\n\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = ParkMenu();

		switch (choice)
		{
		case '1':
			if (player.energy == 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;
			}
			//////////////////Random Event////////////////////////
			//////////////////////////////////////////////////////
			struct Encounter* head = initializeJobEncounters();
			struct Encounter* randomEvent = selectEncounter(head);
			printf("%s\n", randomEvent->description);
			handleJobEvent(randomEvent, &player);
			/////////////////////////////////////////////////////
			/////////////////////////////////////////////////////
			printf("you work a long tiring shift, but hey at least you get paid yippee!");
			//functions:

				//player.energy = 5 (decreases)
				decreaseEnergy(3, player);

				// gets money
				player.cash += 5; // shit wage due to inflation

				//time + 1 (not a full day gone but a section gone)
				player.time++;

			break;
		case '2':


			printf("you leave your job");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}

///////////////// GAME ///////////////////
void MainGame() {

	printf("starting...\n");

	bool randomParkEventOccured = false; //Not really sure where to put this so just gon put here 
	bool randomJobEventOccured = false;
	bool randomSchoolEventOccured = false;
	bool randomApartmentEventOccured = false;
	bool randomCafeEventOccured = false;

	bool continueProgram = true;
	while (continueProgram) {

		char choice = OverWorld();

		switch (choice)
		{
		case '1':

			Apartment();
			break;

		case '2':
			if (player.time == 7)
			{
				printf("Its getting late, you should go back home\n");
				return;
			}
			Cafe();
			break;

		case '3':
			if (player.time > 4)
			{
				printf("Classes are over for the day\n");
				return;
			}
			School();
			break;

		case '4':
			if (player.time == 7)
			{
				printf("Its getting late, you should go back home\n");
				return;
			}
			Park(randomParkEventOccured);
			break;

		case '5':
			if (player.time > 6)
			{
				printf("Shift is over for the day\n");
				return;
			}
			Job();
			break;

		case '6':
			continueProgram = false;
			break;
		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}
