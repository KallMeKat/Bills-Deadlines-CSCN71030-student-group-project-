



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

///////////////// MAIN ///////////////////


FILE* fp;
size_t size = sizeof(PlayerStats);
PlayerStats player[1] = { '\0' };


int main(void)
{
	printf("starting...\n");

	bool continueProgram = true;
	while (continueProgram) {

		char choice = printmenuMain();

		switch (choice)
		{
		case '1':


			//open file
			if ((fp = fopen("player.dat", "r")) == NULL)
			{
				//initalize stats

				player[0].energy = 10;
				player[0].hp = 10;
				player[0].day = 1;


				player[0].cash = 0;
				player[0].time = 0;
				player[0].cha = 1;
				player[0].str = 1;
				player[0].intl = 1;

			}
			else {
				fread(player, size, 1, fp);
				fclose(fp);
			}



			MainGame(player); 

			break;

		case '2': printf("info program...\n\n");
			PrintInfo();
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


	//save file
		//if the file does not have any contents then there was a save failure 
		if ((fp = fopen("player.dat", "w")) == NULL)
			printf("SAVE FAILURE");
		else //write to file
		{
			fwrite(player, size, 1, fp);
			fclose(fp);

		}
}
