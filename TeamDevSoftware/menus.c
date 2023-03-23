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
	printf("3. Go to School\n");
	printf("4. Go to the park\n");
	printf("5. Go to your job\n ");
	printf("6. Exit to main menu (will be moved to apartment loop)\n");

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

char CafeMenu(void)
{
	printf_s("\n");
	printf_s("you are inside a lovely quant cafe with soft jazz playing in the background");

	printf("\nTo choose a function, enter its label: \n");
	printf("1. Go to study\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}

char SchoolMenu(void)
{
	printf_s("\n");
	printf_s("you are at school and have to rush to your classes ");

	printf("\nTo choose a function, enter its label: \n");
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
	printf_s("you are at Allan Gardens enjoying the sun");

	printf("\nTo choose a function, enter its label: \n");
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
	printf_s("you are working at your part time job - Mckhonalds");

	printf("\nTo choose a function, enter its label: \n");
	printf("1. Go work\n");
	printf("2. Leave\n");


	char choice;
	printf("\nEnter Choice: ");
	scanf(" %c", &choice); //return to main input

	return choice;
}