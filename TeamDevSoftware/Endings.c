#include <stdio.h>
#include "PlayerStats.h"

void endingsFunction(PlayerStats stats[]) {

    if (stats[PLAYER].cash == 70 && stats[PLAYER].str == 10 && stats[PLAYER].cha == 10 && stats[PLAYER].intl == 10) {
        printf("BEST ENDING: You are a massive gigachad! You are strong, smart, rizzmaster and payed your rent on time!");
    }
    else if (stats[PLAYER].cash == 70 && stats[PLAYER].str <= 9 && stats[PLAYER].cha <= 9 && stats[PLAYER].intl <= 9) {
        printf("NEUTRAL ENDING: You payed your rent on time, but you are a basement dweller and play too much dead by daylight. You also don't have much rizz or intelligence. ");
    }
    else if (stats[PLAYER].cash == 70 && stats[PLAYER].str == 10 && stats[PLAYER].cha <= 9 && stats[PLAYER].intl <= 9) {
        printf("GOOD ENDING: You payed your rent on time, and are quite the strong person working at the gym. Unfotunately you aren't the smartest and don't have rizz ");
    }
    else if (stats[PLAYER].cash == 70 && stats[PLAYER].str == 10 && stats[PLAYER].cha == 10 && stats[PLAYER].intl <= 9) {
        printf("GOOD ENDING: You payed your rent on time, qre very strong and have immaculate rizz but don't have the brains to impress your classmates ");
    }
    else {
        printf("BAD ENDING: You did not pay your rent on time and were kicked out of your appartment! You have no redeemable qualities");
    }
}
