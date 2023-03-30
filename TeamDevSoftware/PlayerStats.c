#include "PlayerStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



//hp 

int damagePlayer(int scale, PlayerStats stats[]) // decrements from players health by a specific amount
{
	return stats[PLAYER].hp -= scale;
}

int healPlayer(int scale, PlayerStats stats[]) // increments players health by a specific amount
{
	return stats[PLAYER].hp += scale;
}

//energy
int decreaseEnergy(int scale, PlayerStats stats[])
{
	return stats[PLAYER].energy -= scale;
}

int increaseEnergy(int scale, PlayerStats stats[])
{
	return stats[PLAYER].energy += scale;
}

int resetEnergy(PlayerStats stats[])
{
	return stats[PLAYER].energy = 10;
}


//time
int increaseTime(int scale, PlayerStats stats[])
{
	return stats[PLAYER].time += scale;
}
int decreaseTime(int scale, PlayerStats stats[])
{
	return stats[PLAYER].time -= scale;
}

int increaseDay(int scale, PlayerStats stats[])
{
	return stats[PLAYER].day += scale;
}

//money 

int increaseCASH(int scale, PlayerStats stats[])
{
	return stats[PLAYER].cash += scale;
}
int decreaseCASH(int scale, PlayerStats stats[])
{
	return stats[PLAYER].cash -= scale;
}



// increments a specific stat by one


int levelIntl(int scale, PlayerStats stats[])
{
	return stats[PLAYER].intl += scale;
}

int levelCha(int scale, PlayerStats stats[])
{
	return stats[PLAYER].cha += scale;
}

int loseCha(int scale, PlayerStats stats[])
{
	return stats[PLAYER].cha -= scale;
}


int levelStr(int scale, PlayerStats stats[])
{
	return stats[PLAYER].str += scale;
}




//print

void printStats(PlayerStats stats[])
{
	printf("\n\n You have %d HP, %d ENERGY. The TIME is %d and it is DAY %d. You have %d CASH in your pocket \n\n", stats[PLAYER].hp, stats[PLAYER].energy, stats[PLAYER].time, stats[PLAYER].day, stats[PLAYER].cash);

	printf("Your Stats: \n");
	printf("\nSTR %d\n", stats[PLAYER].str);
	printf("\nCHA %d\n", stats[PLAYER].cha);
	printf("\nINTL %d\n", stats[PLAYER].intl);

}





//unimplemented

/*

bool diceRoll(int stat) // action probability, probability changes based on players level in that skill
{
	int random = rand() % 100 * stat;
	if (random < 50)
	{
		return false;
	}
	else
	{
		return true;
	}

}

*/