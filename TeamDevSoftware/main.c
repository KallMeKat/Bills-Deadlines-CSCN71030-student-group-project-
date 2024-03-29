//Group 16
//Amro Belbeisi
//Katarina Lukic
//Naryan Sambhi
//Aleks Grujicic
//#define CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include "PlayerStats.h"
#include "Menus.h"
#include "game.h"
#include "randEvent.h"
#include <stdlib.h>

///////////////// MAIN ///////////////////

//file creation 
FILE* fp;
size_t size = sizeof(PlayerStats);
PlayerStats player[1] = { '\0' };

//main with the command line arguments 
int main(int argc, char* argv[])//set as file name as command like argument "Filename.dat"
{   
    if (argc != 2)         
    {
        fprintf(stderr, "\n\nPlease insert a save file via command\n\nUsage: %s source destination\n\n FILE NAME 'PLAYER.DAT'\n\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    bool continueProgram = true;
    while (continueProgram) {

        char choice = printmenuMain();

        switch (choice)
        {
        //if the user chooses to start the game a file will be created 
        case '1':


            //open file
                if ((fp = fopen(argv[1], "r")) == NULL)
            {
                //initalize stats

                player[PLAYER].energy = 10;
                player[PLAYER].hp = 10;
                player[PLAYER].day = 0;


                player[PLAYER].cash = 0;
                player[PLAYER].time = 0;
                player[PLAYER].cha = 0;
                player[PLAYER].str = 0;
                player[PLAYER].intl = 0;

            }
            else {
                fread(player, size, 1, fp);
                fclose(fp);
            }

            MainGame(player);

            break;

        //if the user wants to see the game information they choose option 2 
        case '2': printf("info program...\n\n");
            PrintInfo();
            break;

        //option 3 exits out of the program 
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
    if ((fp = fopen(argv[1], "w")) == NULL)
        printf("SAVE FAILURE");
    else //write to file
    {
        fwrite(player, size, 1, fp);
        fclose(fp);

    }
}