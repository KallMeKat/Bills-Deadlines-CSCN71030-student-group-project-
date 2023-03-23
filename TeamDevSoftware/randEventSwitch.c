//Group Info Here

#include <stdio.h>
#include "randEvent.h"

void eventOne() {	
	//if else statements to chose your response to situation

	//call function to effect either hp, enery or money based on option selected
}

void eventTwo() {
	//if else statements to chose your response to situation

	//call function to effect either hp, enery or money based on option selected 
}

void eventThree() {
	//if else statements to chose your response to situation

	//call function to effect either hp, enery or money based on option selected
}


int main(void)
{
	struct Encounter* head = createEncounter(1,"A homeless person has robbed you at knifepoint.");
	struct Encounter* second = createEncounter(2,"You've been hit by a car on your way to school.");
	struct Encounter* third = createEncounter(3, "The groupchats messages are leaked to all your future employers.");

	head->next = second;
	second->next = third;
	third->next = NULL;

	struct Encounter* randomEvent = selectEncounter(head);
	printf("%s\n", randomEvent->description);

	switch (randomEvent->id) {
	case 1:
		eventOne();
		break;

	case 2:
		eventTwo();
		break;

	case 3:
		eventThree();
		break;

	default:
		printf("Unknown event!\n");
		break;
	}

	return 0;
}
