//Group Info Here
// Amro Belbeisi

#include <stdio.h>
#include "PlayerStats.h"

///////////////// MAIN ///////////////////


int main(void)
{
	//needs open file
		//or create file
			//initalize array of player stats

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
			//load
				//look file save data file
				//if non found create new, intialize array of player starting stats


			//temporary -> start game prototype directly
			MainGame();

			break;
		case '2': printf("info program...\n");
			//info
			//how to play and what project is
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
