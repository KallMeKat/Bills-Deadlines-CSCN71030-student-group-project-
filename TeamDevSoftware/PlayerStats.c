#include "PlayerStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
time_t t;

int damagePlayer(int scale, PlayerStats stats) // decrements from players health by a specific amount
{
	return stats.hp -= scale;
}

int levelStat(int stat) // increments a specific stat by one
{
	return stat++;
}

int healPlayer(int scale, PlayerStats stats) // increments players health by a specific amount
{
	return stats.hp += scale;
}

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

int decreaseEnergy(int scale, PlayerStats stats)
{
	return stats.energy -= scale;
}