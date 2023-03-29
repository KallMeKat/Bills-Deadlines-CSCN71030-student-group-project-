//Group 16
// Amro Belbeisi
//Katarina Lukic
//Naryan Sambhi
//Aleks Gru
//#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PlayerStats.h"
#include "Menus.h"
#include "game.h"
#define GAMESIZE 100

///////////// MAIN ///////////////////


int main(void)
{
	//needs open file
		//or create file
			//initalize array of player stats

//player struct not implemented yet

//FUNCTION

//willl move this out of main later
    FILE* fp;
    size_t size = sizeof(PlayerStats);

	//PlayerStats player;

    //if no contents detected:


    if ((fp = fopen("game.dat", "r")) == NULL)
    {
		
			player.energy = false; //false == empty / false == 0
			player.day = false; //id of position
		
    }
    else //else, if file detected, read status of the menu items and close
    {
		while (fp = fopen("game.dat", "r") != EOF)
		{
			fp = fopen("game.dat", "r");
		}
        fclose(fp);
    }


    //save to file function here

    //if the file does not have any contents then there was a save failure 
    if ((fp = fopen("game.dat", "w")) == NULL)
        printf("SAVE FAILURE");
    else //write to file
    {
		while (fp = fopen("game.dat", "w") != EOF)
		{
			fp = fopen("game.dat", "w");
		}
        //close the file to end the process
        fclose(fp);
    }


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
