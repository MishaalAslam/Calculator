#define _CRT_SECURE_NO_WARNINGS


#include<stdlib.h>
#include<stdio.h>
#include<time.h>


#define ROWS 3
#define COLS 3
#define SIZE 30



void ticTac(char arr[][COLS] , char[], char);
void board(char[][COLS]);
void checkwin(char[][COLS] , char[]);
int check = 0;

int main()
{
	srand(time(0));
	int pl1[SIZE] , pl2[SIZE];
	char array[ROWS][COLS] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	int choice;


	printf("\t\t\t\tTIC TAC TOE\t\t\t\t\t\n\n");
	printf("\t\t\t     By MISHAAL ASLAM\t\t\n\n");
	printf("\t\t\t\tBITF21M526\t\t\n\n\n");

	char mark1, mark2;
	if (rand() % 2 + 1 == 2)
	{
		mark1 = 'X';
		mark2 = 'O';
	}
	else if (rand() % 2 + 1 == 1)
	{
		mark1 = 'O';
		mark2 = 'X';
	}

	printf("************************************************INSTRUCTIONS************************************************\n\n");
	do
	{
		printf("START\t\tEnter 1\n");
		printf("HELP\t\tEnter 2\n");
		printf("EXIT\t\tEnter 3\n");
		scanf("%d", &choice);
		
		if (choice == 1)
		{
			printf("\n\n************************************************START************************************************\n\n");
			printf("Enter name of player 1:");
			scanf("%s", &pl1);

			printf("Enter name of player 2:");
			scanf("%s", &pl2);

			printf("\n\n\n");
			printf("\t\t\t%s(%c)-%s(%c)\n\n", pl1, mark1, pl2, mark2);

			board(array);

			for (int i = 0; i < ROWS * COLS; i++)
			{
				if (check == 0)
				{
					if (i % 2 == 0)
					{
						ticTac(array, pl1, mark1);
					}
					else if (i % 2 != 0)
					{
						ticTac(array, pl2, mark2);
					}
				}
				
			}
			
		}
		else if (choice == 2)
		{
			printf("Following pattern is diplayed\n");
			board(array);
			printf("Each player will be entering the number to put respective X or O in the desired position . Player who gets a combination of three same characers either diagonal or horizontally or vertically will be declared as the winner \nEnjoy the game!bethe winner!\n\n\n");
			printf("\n");
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			printf("Wrong choice\nEnter Again: ");
			scanf("%d", &choice);
		}
	} while (choice != 3);

	

	return 0;
}

void ticTac(char arr[][COLS], char name[], char symb)
{
	int choice = 0, flag = 0;
	int res = 0;
	
	printf("%s Enter your Choice: ", name);
	scanf("%d", &choice);


	do
	{
		
		if ((choice == 1) && (arr[0][0] == '1'))
		{
			arr[0][0] = symb;
		}
		else if ((choice == 2) && (arr[0][1] == '2'))
		{
			arr[0][1] = symb;
		}
		else if ((choice == 3) && (arr[0][2] == '3'))
		{
			arr[0][2] = symb;
		}
		else if (choice == 4 && arr[1][0] == '4')
		{
			arr[1][0] = symb;
		}
		else if (choice == 5 && arr[1][1] == '5')
		{
			arr[1][1] = symb;
		}
		else if (choice == 6 && arr[1][2] == '6')
		{
			arr[1][2] = symb;
		}
		else if (choice == 7 && arr[2][0] == '7')
		{
			arr[2][0] = symb;
		}
		else if (choice == 8 && arr[2][1] == '8')
		{
			arr[2][1] = symb;
		}
		else if (choice == 9 && arr[2][2] == '9')
		{
			arr[2][2] = symb;
		}
		else
		{
			printf("Invalid position.Enter a Valid choice: ");
			scanf("%d", &choice);
			flag = 1;
		}
		board(arr);
		checkwin(arr, name);
		
	} while ((flag == 1) && (res == -1)); 
	
	
}


void board(char a[][COLS])
{
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", a[0][0], a[0][1], a[0][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", a[1][0],a[1][1], a[1][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", a[2][0],a[2][1],a[2][2]);
	printf("     |     |     \n");
}


void checkwin(char a[][COLS] , char name[])
{
	//Row 1
	if ((a[0][0] == a[0][1]) && (a[0][1] == a[0][2]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Row 2
	else if ((a[1][0] == a[1][1]) && (a[1][1] == a[1][2]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Row 3
	else if ((a[2][0] == a[2][1]) && (a[2][1] == a[2][2]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Column 1
	else if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Column 2
	else if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Column 3
	else if ((a[0][0] == a[1][0]) && (a[1][0] == a[2][0]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Left Diagonal
	else if ((a[0][1] == a[1][1]) && (a[1][1] == a[2][1]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//Right Diagonal
	else if ((a[0][2] == a[1][2]) && (a[1][2] == a[2][2]))
	{
		check = 1;
		printf("\n\n*****************************************CONGRATULATIONS******************************************\n\n");
		printf("%s won\n\n", name);
	}
	//All attempts done
	else if ((a[0][0] != '1') && (a[0][1] != '2') && (a[0][2] != '3') && (a[1][0] != '4') && (a[1][1] != '5') && (a[1][2] != '6') && (a[2][0] != '7') && (a[2][1] != '8') && (a[2][2] != '9'))
	{
		
		printf("OOPS!! MAtch Drawn\n\n");
	}
	//In progress
	else
	{
		//return -1;
	}

}




