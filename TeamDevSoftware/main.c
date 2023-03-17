//Group Info Here

#include <stdio.h>
#include "randEvent.h"

int main(void)
{


	struct Encounter* head = createEncounter("A homeless person has robbed you at knifepoint.");
	head->next = createEncounter("You are hit by a car.");
	head->next = createEncounter("The groupchats messages are leaked to all your future employers");

	struct Encounter* randomEvent = selectEncounter(head);
	printf("%s\n", randomEvent->description);

	return 0;
}
