#define _CRT_SECURE_NO_WARNINGS


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

			printf("\n\n\n\nyou are in cafe loop\n\n\n\n");


			//cafe 
				//to study
					//consume energy 
					//gain intelligence stat
			break;
		case '3':
			continueProgram = false;
			break;
		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}
