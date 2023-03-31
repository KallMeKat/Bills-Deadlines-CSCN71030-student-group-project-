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

///////////////// MAIN ///////////////////


FILE* fp;
size_t size = sizeof(PlayerStats);
PlayerStats player[1] = { '\0' };


int main(void)
{
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