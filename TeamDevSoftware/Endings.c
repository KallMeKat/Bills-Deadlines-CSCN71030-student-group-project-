#include <stdio.h>
#include "PlayerStats.h"

void endingsFunction(PlayerStats stats[]) {

    if (stats[PLAYER].cash == 140 && stats[PLAYER].str == 10 && stats[PLAYER].cha == 10 && stats[PLAYER].intl == 10) {
        printf("\n\nBEST ENDING: You are a massive gigachad! You are strong, smart, rizzmaster and payed your rent on time!\n\n");
    }
    else if (stats[PLAYER].cash == 140 && stats[PLAYER].str <= 9 && stats[PLAYER].cha <= 9 && stats[PLAYER].intl <= 9) {
        printf("\n\nNEUTRAL ENDING: You payed your rent on time, but you are a basement dweller and play too much dead by daylight. You also don't have much rizz or intelligence\n\n");
    }
    else if (stats[PLAYER].cash == 140 && stats[PLAYER].str == 10 && stats[PLAYER].cha <= 9 && stats[PLAYER].intl <= 9) {
        printf("\n\nGOOD ENDING: You payed your rent on time, and are quite the strong person working at the gym. Unfotunately you aren't the smartest and don't have rizz\n\n");
    }
    else if (stats[PLAYER].cash == 140 && stats[PLAYER].str == 10 && stats[PLAYER].cha == 10 && stats[PLAYER].intl <= 9) {
        printf("\n\nGOOD ENDING: You payed your rent on time, are very strong and have immaculate rizz but don't have the brains to impress your classmates\n\n");
    }
    else {
        printf("\n\nBAD ENDING: You did not pay your rent on time and were kicked out of your apartment! You have no redeemable qualities\n\n");
    }
}
