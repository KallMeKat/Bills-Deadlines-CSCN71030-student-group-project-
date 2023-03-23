#define _CRT_SECURE_NO_WARNINGS
#include "Menus.h"

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
			printf("you go study for some time, feeling a bit tired but understanding the material more");
			//functions:
				
				//player.energy = 5 (decreases)
			    //time + 1 (not a full day gone but a section gone)

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
			printf("you go to your classes incredibly bored about the material but feel a bit more understnading the material");
			//functions:

				//player.energy = 5 (decreases)
				// Intelligence increases 
				//time + 1 (not a full day gone but a section gone)

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

void Park(void) {

	printf("\n\n\n\nyou are inside the park\n\n\n\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = ParkMenu();

		switch (choice)
		{
		case '1':
			printf("you go to take a walk in the part feeling much stronger in your legs after the workout");
			//functions:

				//player.energy = 5 (decreases)
				// Strength increases
				//time + 1 (not a full day gone but a section gone)

			break;
		case '2':


			printf("you leave the park");

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
			printf("you work a long tiring shift, but hey at least you get paid yippee!");
			//functions:

				//player.energy = 5 (decreases)
				// gets money
				//time + 1 (not a full day gone but a section gone)

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

	bool continueProgram = true;
	while (continueProgram) {

		char choice = OverWorld();

		switch (choice)
		{
		case '1':

			Apartment();
			break;

		case '2':

			Cafe();
			break;

		case '3':

			School();
			break;

		case '4':

			Park();
			break;

		case '5':

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
