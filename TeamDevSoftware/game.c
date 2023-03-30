//#define _CRT_SECURE_NO_WARNINGS
#include "Menus.h"
#include "game.h"
#include "randEvent.h"
#include "PlayerStats.h"
#include <stdio.h>
#include <stdbool.h>

///////////////// AREAS ///////////////////
void Apartment(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = ApartmentMenu();

		switch (choice)
		{
		case '1':
			printf("you go to sleep, you fill energized (plus to next day & energy)\n");

			//reset energy, time and increase day
			increaseDay(1, arr);
			resetEnergy(arr);

			printStats(arr);

			break;
		case '2':
			printf("you leave your apartment\n");
			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}



}
void Cafe(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = CafeMenu();

		switch (choice)
		{
		case '1':
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you need to go back home and get some sleep\n");
				return;

			}
			if (arr[PLAYER].cash <= 5)
			{
				printf("You go to pay only to realize you dont even have the 5$ to pay. You embarrassingly walk feeling less charismatic then before.");


				loseCha(1, arr);

				increaseTime(1, arr);

				printStats(arr);

				return;
			}



			printf("you purchase a fresh cup of coffee and enjoy a short conversation with the barista. You feel energize and more charismatic\n");

			decreaseCASH(5, arr);
			increaseTime(1, arr);
			levelCha(1, arr);
			increaseEnergy(1, arr);

			printStats(arr);


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

void School(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = SchoolMenu();

		switch (choice)
		{
		case '1':
			if (arr[0].time > 4)
			{
				printf("Classes are over for the day\n");
				return;
			}
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;
			}

			printf("you go to your classes incredibly bored about the material but feel a bit more understnading the material\n");

			decreaseEnergy(5, arr);
			levelIntl(1, arr);
			increaseTime(1, arr);

			printStats(arr);

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

void Park(PlayerStats arr[]) {


	bool continueProgram = true;
	while (continueProgram) {

		char choice = ParkMenu();

		switch (choice)
		{
		case '1':
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;

			}

			printf("you go to take a walk in the part feeling much stronger in your legs after the workout\n");

			decreaseEnergy(2, arr);
			levelStr(1, arr);
			increaseTime(1, arr);

			printStats(arr);


			break;
		case '2':

			/////////////////Random Event///////////////
			///////////////////////////////////////////
			struct Encounter* head = initializeEncounters();
			struct Encounter* randomEvent = selectEncounter(head);
			printf("%s\n", randomEvent->description);
			handleEvent(randomEvent, arr);
			//////////////////////////////////////////
			//////////////////////////////////////////


			printf("you leave the park");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}

void Job(PlayerStats arr[]) {


	bool continueProgram = true;
	while (continueProgram) {

		char choice = JobMenu();

		switch (choice)
		{
		case '1':

			if (arr[0].time > 6)
			{
				printf("Shift is over for the day\n");
				return;
			}
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;
			}

			/////////////////Random Event///////////////
			///////////////////////////////////////////
			struct Encounter* head = initializeJobEncounters();
			struct Encounter* randomEvent = selectEncounter(head);
			printf("%s\n", randomEvent->description);
			handleJobEvent(randomEvent, arr);
			//////////////////////////////////////////
			//////////////////////////////////////////

			printf("you work a long tiring shift, but hey at least you get paid yippee!\n");

			decreaseEnergy(3, arr);
			increaseCASH(5, arr);
			increaseTime(1, arr);

			printStats(arr);

			break;
		case '2':


			printf("you leave your job\n");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}

///////////////// GAME ///////////////////
void MainGame(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = OverWorld();

		switch (choice)
		{
		case '1':
			Apartment(arr);
			break;

		case '2':
			if (arr[0].time >= 7)
			{
				printf("Its getting late, you head back home\n");
				Apartment(arr);
			}
			Cafe(arr);
			break;

		case '3':
			School(arr);
			break;


		case '4':
			if (arr[0].time >= 7)
			{
				printf("Its getting late, you head back home\n");
				Apartment(arr);
			}
			Park(arr);
			break;


		case '5':
			Job(arr);
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
