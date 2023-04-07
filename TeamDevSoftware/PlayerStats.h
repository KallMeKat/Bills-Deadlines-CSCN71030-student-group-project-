#pragma once
#include <stdbool.h>

//player has an index of 0 to pass arrays
#define PLAYER 0

//the wait variable for the dice roll to make it wait a couple seconds before outputing 
#define WAIT 2000

//the stats of the player
typedef struct playerstats
{

	//very basic stats such as teh energy and he day to keep teh game going 
	int energy;
	int day;
	int cash;
	int time;


	//others stats that effect the endings such as hp or strength 
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
int loseIntl(int scale, PlayerStats stats[]);

int levelCha(int scale, PlayerStats stats[]);

int loseCha(int scale, PlayerStats stats[]);

int levelStr(int scale, PlayerStats stats[]);

int loseStr(int scale, PlayerStats stats[]);

void resetAll(PlayerStats player[]);


//print all the stats

void printStats(PlayerStats stats[]);


//dice roll for the main stats 

bool DiceRollCharisma(PlayerStats stats[]);

bool DiceRollStrength(PlayerStats stats[]);

bool DiceRollIntelligence(PlayerStats stats[]);

