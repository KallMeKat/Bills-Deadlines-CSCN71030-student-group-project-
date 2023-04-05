#include <stdio.h>
#include "PlayerStats.h"

void endingsFunction(PlayerStats stats[]) {

    if (stats[PLAYER].cash == 140 && stats[PLAYER].str == 10 && stats[PLAYER].cha == 10 && stats[PLAYER].intl == 10) {
        printf("\n\nBEST ENDING: Against all odds you managed to pay your rent on time and finish your exams. You've made friends along the way and took good care of yourself!\n\n");
    }
    else if (stats[PLAYER].cash == 140 && stats[PLAYER].str <= 9 && stats[PLAYER].cha <= 9 && stats[PLAYER].intl <= 9) {
        printf("\n\nNEUTRAL ENDING: You payed your rent on time, but you are a basement dweller and play too much dead by daylight. You failed your exams and barely payed for rent.\n\n");
    }
    else if (stats[PLAYER].cash == 140 && stats[PLAYER].str == 10 && stats[PLAYER].cha <= 9 && stats[PLAYER].intl <= 9) {
        printf("\n\nNEUTRAL ENDING: You payed your rent on time, you took care of yourself however you didn't study enough and failed your final exam\n\n");
    }
    else if (stats[PLAYER].cash == 140 && stats[PLAYER].str == 10 && stats[PLAYER].cha == 10 && stats[PLAYER].intl <= 9) {
        printf("\n\nGOOD ENDING: You payed your rent on time, are very strong and have immaculate rizz but you still managed to fail your final exam.\n\n");
    }
    else {
        printf("\n\nBAD ENDING: You did not pay your rent on time and were kicked out of your apartment! You have no redeemable qualities, all you do is sleep all day.. you pathetic worm\n\n");
    }
}
