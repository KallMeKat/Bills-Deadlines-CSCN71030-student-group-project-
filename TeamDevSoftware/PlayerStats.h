#pragma once
#include <stdbool.h>

#define PLAYER 0


typedef struct playerstats
{

	//very basics for working overworld:
	int energy;
	int day;
	int cash;
	int time;


	//others stats here - these are unimplemented 
	unsigned int hp;
	unsigned int str;
	unsigned int cha;
	unsigned int intl;
	

} PlayerStats;


//hp 

int damagePlayer(int scale, PlayerStats stats[]);

int healPlayer(int scale, PlayerStats stats[]);


//energy
int decreaseEnergy(int scale, PlayerStats stats[]);

int increaseEnergy(int scale, PlayerStats stats[]);

int resetEnergy(PlayerStats stats[]);

//time
int increaseTime(int scale, PlayerStats stats[]);

int decreaseTime(int scale, PlayerStats stats[]);

int increaseDay(int scale, PlayerStats stats[]);

//cash
int increaseCASH(int scale, PlayerStats stats[]);

int decreaseCASH(int scale, PlayerStats stats[]);

//level stats

int levelIntl(int scale, PlayerStats stats[]);

int levelCha(int scale, PlayerStats stats[]);

int loseCha(int scale, PlayerStats stats[]);

int levelStr(int scale, PlayerStats stats[]);

int loseStr(int scale, PlayerStats stats[]);

void resetAll(PlayerStats player[]);


//print

void printStats(PlayerStats stats[]);


//UNIMPLEMENTED: 
/*
bool diceRoll(int stat);
*/
