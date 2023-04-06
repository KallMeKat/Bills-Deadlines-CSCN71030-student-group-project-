//#define _CRT_SECURE_NO_WARNINGS
#include "Menus.h"
#include "game.h"
#include "randEvent.h"
#include "PlayerStats.h"
#include "Endings.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>


#define FINALDAY 14
#define MIDTERM 7
#define MAXCHAR 100
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



			//count down to final day function here
			printf("\n*********************************************************************************************\n");
			printf("** You have %d days until your rents due and your final exam approaches. Prepare yourself.   **\n", FINALDAY - arr[PLAYER].day);
			printf("** You should really study for you final exam and make enough money for rent (140$)...       **\n");
			printf("***********************************************************************************************\n");


			//other day events here 
				//if 3 midterm for ex



			if (arr[PLAYER].day == FINALDAY) {

				endingsFunction(arr);

				resetAll(arr); //resets save file stats

				main(); //calls back to main menu
			}

			if(arr[PLAYER].day == MIDTERM)
			{
				printf("\n*********************************************************************************************\n");
				printf("** Today you have your Comp Sci Midterm and its about bitwise operators and memcpy.			 **\n");
				printf("** You feel nervous go into the exam with confidence...								         **\n");
				printf("***********************************************************************************************\n");

				int a = 12;
				int b = 25;
				int c = a & b;
				int input;
				printf("The first question of the exam is about bitwise operations (oh no), What's the result of %d & %d\n", a, b);
				scanf("%d", &input);
				if (input == 8)
				{
					printf("You feel confident in your answer, you feel smarter\n");
					levelIntl(1, arr);
				}
				else
				{
					printf("You don't feel confident in your answer, you feel dumber\n");
					loseIntl(1, arr);
				}
				char a[] = "FirstString";
				char b[] = "SecondString";
				char c[] = memcpy(a, b, 5);
				char Sinput[MAXCHAR];
				printf("The second question of the exam is about bitwise operations (oh no), What's the result of memcpy('FirstString', 'SecondString', 5) \n");
				scanf("%s", &Sinput);
				if (strcmp(Sinput, c))
				{
					printf("You feel confident in your answer, you feel smarter\n");
					levelIntl(1, arr);
				}
				else
				{
					printf("You don't feel confident in your answer, you feel dumber\n");
					loseIntl(1, arr);
				}
				printf("You continue with the rest of the test\n");
				decreaseEnergy(3, arr);

			}

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
				printf("You find out only after ordering you dont even have the money to pay.");



				bool option = DiceRollCharisma(arr);

				if (option == true) {

					printf("\nyour strong charisma allows you to talk your way out of the embarrasment and you keep your charisma stat\n");
					Sleep(WAIT);

					return;
				}


				printf("\nYou embarrassingly walk away after tripping over your worlds trying to explain that you cant pay. You are feeling less charismatic then before.\n");
				Sleep(WAIT);

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

			bool option = DiceRollIntelligence(arr);

			if (option = true)
			{
				printf("You feel as if you're beginning to understand the material better. You gain an extra intelligence point\n");
				levelIntl(1, arr);
			}

			printf("You still struggle with teh material but feel smarter anyways.. \n");

			decreaseEnergy(5, arr);
			levelIntl(1, arr);
			increaseTime(1, arr);

			printStats(arr);

			break;
		case '2':

			printf("you leave the school\n");

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
				printf("There are no more shifts available today\n");
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
