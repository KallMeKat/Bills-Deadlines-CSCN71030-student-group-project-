#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdbool.h>

///////////////// MENUS ///////////////////
char printmenuMain(void)
{
	printf_s("\n");
	printf_s("****************************\n");
	printf_s("**        Working         **\n");
	printf_s("**         Title          **\n");
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
	printf_s("\n");
	printf_s("you are within the wide city of Toronto, where will you go?");

	printf("\nTo choose a function, enter its label: \n");
	printf("1. Go to apartments\n");
	printf("2. Go to Cafe\n");
	printf("3. Exit to main menu (will be moved to apartment loop)\n");

	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}


////////////////// AREAS /////////////////


char ApartmentMenu(void)
{
	printf_s("\n");
	printf_s("you are within your depressing small apartment");

	printf("\nTo choose a function, enter its label: \n");
	printf("1. Go to sleep\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}