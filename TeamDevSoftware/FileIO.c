////This is where the file input /output would go 
////Katarina Lukic
#include <stdlib.h>
#include <stdio.h>
#include "PlayerStats.h"

FILE* fp;
size_t size = sizeof(PlayerStats);
PlayerStats player[1] = { '\0' };

void file_open(void) {
	
	if ((fp = fopen("player.dat", "r")) == NULL)
	{

		player[0].energy = 100; //initla value of the energy stat
		player[0].cash = 0;
		player[0].day = 0; // inital value of the days
		player[0].time = 0;
		player[0].cha = 0;
	}
	else {
	    fread(player, size, 1, fp);
	    fclose(fp);
		}
}

void file_save(void) {

	//if the file does not have any contents then there was a save failure 
	if ((fp = fopen("player.dat", "w")) == NULL)
		printf("SAVE FAILURE");
	else //write to file
	{
		fwrite(player, size, 1, fp);
		fclose(fp);
	}
	
}