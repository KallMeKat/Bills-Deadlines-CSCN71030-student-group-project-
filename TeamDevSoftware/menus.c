//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

///////////////// MENUS ///////////////////
char printmenuMain(void)
{
	printf_s("\n");
	printf_s("****************************\n");
	printf_s("**                        **\n");
	printf_s("**    Bills & Deadlines   **\n");
	printf_s("**                        **\n");
	printf_s("****************************\n");

	printf("\nTo choose a function, enter its label: \n");
	printf("1. start game\n");
	printf("2. info\n");
	printf("3. Exit\n");

	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}
  

char OverWorld(void)
{
	printf_s("\n\n");
	printf_s("you are within the wide city of Toronto, where will you go?\n");

	printf("\nTo choose a function, enter its label: \n\n");
	printf("1. Go to apartments\n");
	printf("2. Go to Cafe\n");
	printf("3. Go to School\n");
	printf("4. Go to the park\n");
	printf("5. Go to your job\n");
	printf("6. Exit Game\n");

	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}


////////////////// AREAS /////////////////


char ApartmentMenu(void)
{
	printf_s("\n");
	printf_s("you are within your depressing small student apartment\n");

	printf("\nTo choose a function, enter its label: \n\n");
	printf("1. Go to sleep\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}

char CafeMenu(void)
{
	printf_s("\n");
	printf_s("you are inside a lovely quaint cafe with soft jazz playing in the background\n");

	printf("\nTo choose a function, enter its label: \n\n");
	printf("1. Get some coffee\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}

char SchoolMenu(void)
{
	printf_s("\n");
	printf_s("you are at school and have to rush to your classes\n ");

	printf("\nTo choose a function, enter its label: \n\n");
	printf("1. Go to class\n");
	printf("2. Skip\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}

char ParkMenu(void)
{
	printf_s("\n");
	printf_s("you are at Allan Gardens enjoying the sun\n");

	printf("\nTo choose a function, enter its label: \n\n");
	printf("1. Go take a lovely walk\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}

char JobMenu(void)
{
	printf_s("\n");
	printf_s("you are working at your part time job - Walmart\n");

	printf("\nTo choose a function, enter its label: \n\n");
	printf("1. Go work\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}

void PrintInfo(void) {

	printf("Welcome to the insert name here simulator!\n\n");
	printf("The main goal is to pay your rent on time and have the highest stats\n\n");
	printf("The game mechanics are simple: just type in a number to traverse to a location\n\n");
	printf("But don't dillydally around, you have a limited time per day and also need to pay your rent within 2 weeks!\n\n");
	printf("There are multiple endings based on your stats so try to get them all, and manage your tiem wisely.\n\n");
	printf("an you get the ultimate endin? its up to you :3 \n\nGood luck and have fun!\n\n");
}