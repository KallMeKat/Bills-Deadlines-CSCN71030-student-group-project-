#include "PlayerStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

#define RESET 10

//hp 

int damagePlayer(int scale, PlayerStats stats[]) // decrements from players health by a specific amount
{
	return stats[PLAYER].hp -= scale;
}

int healPlayer(int scale, PlayerStats stats[]) // increments players health by a specific amount
{
	return stats[PLAYER].hp += scale;
}

int resetHealth(PlayerStats stats[])
{
	return stats[PLAYER].hp = RESET;
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
	return stats[PLAYER].energy = RESET;
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

int loseStr(int scale, PlayerStats stats[])
{
	return stats[PLAYER].str -= scale;
}

int loseIntl(int scale, PlayerStats stats[])
{
	return stats[PLAYER].intl -= scale;
}

//resets all stats when the user starts a new game 
void resetAll(PlayerStats player[]) 
{

	player[PLAYER].energy = 10;
	player[PLAYER].hp = 10;
	player[PLAYER].day = 0;


	player[PLAYER].cash = 0;
	player[PLAYER].time = 0;
	player[PLAYER].cha = 0;
	player[PLAYER].str = 0;
	player[PLAYER].intl = 0;
}




//print

void printStats(PlayerStats stats[])
{
	printf("\n\nYou have %d HP, %d ENERGY. The TIME is %d and it is DAY %d. You have %d CASH in your pocket \n\n", stats[PLAYER].hp, stats[PLAYER].energy, stats[PLAYER].time, stats[PLAYER].day, stats[PLAYER].cash);

	printf("Your Stats: \n");
	printf("\nSTR %d\n", stats[PLAYER].str);
	printf("\nCHA %d\n", stats[PLAYER].cha);
	printf("\nINTL %d\n", stats[PLAYER].intl);

}


bool DiceRollCharisma(PlayerStats stats[]) // action probability, probability changes based on players level in that skill
{
	printf("\n\nDICE ROLL!\n\n");
	Sleep(WAIT);

	int random = rand() % 100 * stats->cha;
	if (random < 50)
	{

		printf("FAIL\n");

		return false;
	}
	else
	{
		printf("PASS\n");

		return true;
	}

}

bool DiceRollStrength(PlayerStats stats[]) // action probability, probability changes based on players level in that skill
{
	printf("\n\nDICE ROLL!\n\n");
	Sleep(WAIT);

	int random = rand() % 100 * stats->str;
	if (random < 50)
	{
		printf("FAIL\n");

		return false;
	}
	else
	{

		printf("PASS\n");

		return true;
	}

}

bool DiceRollIntelligence(PlayerStats stats[]) // action probability, probability changes based on players level in that skill
{
	printf("\n\nDICE ROLL!\n\n");
	Sleep(WAIT);

	int random = rand() % 100 * stats->intl;
	if (random < 50)
	{

		printf("FAIL\n");

		return false;
	}
	else
	{

		printf("PASS\n");

		return true;
	}

}