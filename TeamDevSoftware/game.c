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

///////////////// AREAS ///////////////////
void Apartment(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = ApartmentMenu();

		switch (choice)
		{

		//first option the player goes to sleep
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

			//if the gme is done aka the 14 days have passed
			if (arr[PLAYER].day == FINALDAY) {

				endingsFunction(arr);

				resetAll(arr); //resets save file stats

				main(); //calls back to main menu
			}

			//if the player is on day 7 then they will have their midterm so they have a chance to increase their intelligene stat 
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

				//first question with bitwise operators 
				printf("The first question of the exam is about bitwise operations (oh no), What's the result of %d & %d\n", a, b);
				scanf("%d", &input);
				if (input == 8)
				{   //correct answer your intelligence increases otherwise you lose it 
					printf("You feel confident in your answer, you feel smarter\n");
					levelIntl(1, arr);
				}
				else
				{
					printf("You don't feel confident in your answer, you feel dumber\n");
					loseIntl(1, arr);
				}

				//second question with memcpy
				char Sa[MAXCHAR] = "FirstString";
				char Sb[MAXCHAR] = "SecondString";
				
				char Sinput[MAXCHAR];
				printf("The second question of the exam is about bitwise operations (oh no), What's the result of memcpy('FirstString', 'SecondString', 5) \n");
				scanf("%s", &Sinput);
				if (strcmp(Sinput, memcpy(Sa, Sb, 5)) == 0)
				{   
					//correct answer you gain intelligence, otherwise you lose it 
					printf("You feel confident in your answer, you feel smarter\n");
					levelIntl(1, arr);
				}
				else
				{
					printf("You don't feel confident in your answer, you feel dumber\n");
					loseIntl(1, arr);
				}

				//your energry would decrease after the exam
				printf("You continue with the rest of the test\n");
				decreaseEnergy(3, arr);

			}

			break;
		//second option the user leaves the appartment to go to a different location 
		case '2':
			printf("you leave your apartment\n");
			continueProgram = false;
			break;

			//any other entry is invalid and the menu loops back 
		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}



}

//second location is the cafe 
void Cafe(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		//the choice is printing the cafemenu 
		char choice = CafeMenu();

		switch (choice)
		{
		
		//the first option would be if the user wants a cup of coffee, based on their stats they can have one or not 
		case '1':

			//if the user is too tired then no coffee for them
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you need to go back home and get some sleep\n");
				return;

			}
			//if they don't have the money then a dice roll would happen so they have a change to gain or lose charisma 
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

			//if the player does have enough money they increase their charaisma and lose money 
			printf("you purchase a fresh cup of coffee and enjoy a short conversation with the barista. You feel energize and more charismatic\n");

			decreaseCASH(5, arr);
			increaseTime(1, arr);
			levelCha(1, arr);
			increaseEnergy(1, arr);

			printStats(arr);

			break;

		//if they leave the cafe they go to another location 
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

//the third location is the school 
void School(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = SchoolMenu();

		switch (choice)
		{

		//if their time is over or their energy is low they cannot go to their classes 
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

			//you get an option to increase your intelligence with a dice roll 
			printf("you go to your classes incredibly bored about the material but feel a bit more understnading the material\n");

			bool option = DiceRollIntelligence(arr);

			if (option = true)
			{
				printf("You feel as if you're beginning to understand the material better. You gain an extra intelligence point\n");
				levelIntl(1, arr);
			}

			//your energy would decrease but your intelligence would increase 
			printf("You still struggle with teh material but feel smarter anyways.. \n");

			decreaseEnergy(5, arr);
			levelIntl(1, arr);
			increaseTime(1, arr);

			printStats(arr);

			break;

		//if the player wants to leave the school to go to another location 
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

//the fourth location is the park 
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

			//if the player wants to go on a walk it would increase their strength stat 
			printf("you go to take a walk in the part feeling much stronger in your legs after the workout\n");

			decreaseEnergy(2, arr);
			levelStr(1, arr);
			increaseTime(1, arr);

			printStats(arr);
			break;

		//once the user leaves the park a random event would trigger
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

//the final location would be the job 
void Job(PlayerStats arr[]) {


	bool continueProgram = true;
	while (continueProgram) {

		char choice = JobMenu();

		switch (choice)
		{
		case '1':

			//if the time is up or the player's energy is too low they cannot do their job 
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
			//at the job a random event would trigger 
			

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

			//if the user leaves their job to go another location 
			printf("you leave your job\n");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}
//main game with the menus 

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
