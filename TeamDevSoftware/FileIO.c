////This is where the file input /output would go 
////Katarina Lukic 
//#include <stdio.h>
//
//#define GAMESIZE 100
//
////player struct not implemented yet
//
////FUNCTION
//
////willl move this out of main later
//int main(void)
//{
//	FILE* fp;
//	size_t size = sizeof(PLAYER);
//
//	PLAYER player[GAMESIZE] = { '\0' };
//
//	//if no contents detected:
//
//	if ((fp = fopen("game.dat", "r")) == NULL)
//	{
//		for (int i = 0; i < 5; i++) //creating 5 empty player items
//		{
//			player[i].status = false; //false == empty / false == 0
//			player[i].id = i; //id of position
//		}
//	}
//	else //else, if file detected, read status of the menu items and close
//	{
//		fread(player, size, GAMESIZE, fp);
//		fclose(fp);
//	}
//
//
//	//save to file function here
//
//	//if the file does not have any contents then there was a save failure 
//	if ((fp = fopen("game.dat", "w")) == NULL)
//		printf("SAVE FAILURE");
//	else //write to file
//	{
//		fwrite(player, size, GAMESIZE, fp);
//		//close the file to end the process
//		fclose(fp);
//	}
//
//}