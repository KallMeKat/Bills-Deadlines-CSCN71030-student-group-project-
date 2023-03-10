#pragma once
#include <stdbool.h>
typedef struct playerstats
{
	unsigned int hp;
	int str, cha, intl;
	
} PlayerStats;



int damagePlayer(int, PlayerStats);
int levelStat(int stat);
int healPlayer(int scale, PlayerStats stats);
bool diceRoll(int stat);
