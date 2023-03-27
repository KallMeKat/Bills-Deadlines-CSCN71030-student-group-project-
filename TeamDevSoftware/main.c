//Group 16
// Amro Belbeisi
//Katarina Lukic
//Naryan Sambhi
//Aleks Grujicic
//#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PlayerStats.h"
#include "Menus.h"
#include "game.h"
#include "FileIO.h"

///////////////// MAIN ///////////////////


int main(void)
{
	//needs open file
		//or create file
			//initalize array of player stats

//player struct not implemented yet

//FUNCTION

//willl move this out of main later


	printf("starting...\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = printmenuMain();

		switch (choice)
		{
		case '1': printf("start program...\n");

			//start
			//new
				//look file save data file
			//if found create ask if overwrite, -> if yes intialize array of player starting stats
			file_open();
			//if no contents detected:


			//load
				//look file save data file
				//if non found create new, intialize array of player starting stats

			//save to file function here
			file_save();

			//temporary -> start game prototype directly
			MainGame();

			break;
		case '2': printf("info program...\n");
			//info
			//how to play and what project is
			//also add the story here?
			break;
		case '3':
			continueProgram = false;
			break;
		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
	printf("\nending...\n");

}
