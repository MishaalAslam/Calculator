#define _CRT_SECURE_NO_WARNINGS

#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void game();
int bating(int, char[], char[], int);
int score(char[], char[]);
void winner(char*, int, char*, int);

void delay(int sec)
{
	int millisecs = 1000 * sec;
	clock_t start_time = clock();

	while (clock() < start_time + millisecs);
}


int main()
{
	int choice , loop=1;
	
	printf("\n\t\t\t~~~~~~~~~~~~~~~Cricket Game~~~~~~~~~~~~~~~\t\t\t\n\n\n");
	printf("\t\t\t\t     By Mishaal Aslam\t\t\t\n\n");
	printf("\t\t\t\t\tBITF21M526\t\t");


	while (loop == 1)
	{
		printf("\n\n\n\t    Cricket WorldCup\t\t\t\n\t------------------------\t\t\t\n\n\n");
		printf("1) START\t\t\tEnter 1\n2) INSTRUCTIONS\t\t\tEnter 2\n3) EXIT\t\t\t\tEnter 3\n\n");
		scanf("%d", &choice);


		switch (choice)
		{
		case 1:
			game();
			break;
		case 2:
			printf("\t\t\t\tH0W T0 PL@Y\nWhen game starts you have to press any key ,when you press any key computer ");
			printf("will generate random number and that random number will be your runs. When 7 number is generated than you get out so the game totaly depends on your luck. \n\n");
			printf("\t\t\t\tENJOY THE G@ME....\n\n");
			break;
		case 3:
			loop = 0;
			break;
		default:
			printf("\nSorry Wrong Choice\nEnter Your Choice Again.....\n");
			break;
		}
	}
	



	return 0;
}


void game()
{
	int toss, choose;
	int overs;
	int balls;
	char player1[20], player2[20];
	int batselect;
	int score1 = 5000, score2 = 5000;

	printf("\nEnter Name of First Player: ");
	scanf("%s", &player1);
	printf("\nEnter Name of Second Player: ");
	scanf("%s", &player2);

	printf("\nEnter how many overs you want to play: ");
	scanf("%d", &overs);
	
	while (overs > 10 || overs < 1)
	{
		printf("Invalid!! Enter again: ");
		scanf("%d", &overs);
	}
	balls = overs * 6;

	printf("\n\nNow its Time for TOSS\n\n%s choose 1 for HEADS and 2 for TAILS: ", player1);
	scanf("%d", &choose);
	
	while ((choose != 1) && (choose != 2))
	{
		printf("Invalid!!Enter again 1 for HEADS and 2 for TAILS: ");
		scanf("%d", &choose);
	}
	
	srand(time(0));
	toss = rand() % 2 + 1;

	if (toss == choose)
	{
		printf("\n%s won the TOSS\n\nSelect....\n1) Bating\t\t\tEnter 1\n2) Bowling\t\t\tEnter 2\n" , player1);
		scanf("%d", &batselect);
		while (batselect < 1 || batselect > 2)
		{
			printf("\nINVALID!! %s Enter your choice Again:\n\nSelect....\n1) Bating\t\t\tEnter 1\n2) Bowling\t\t\tEnter 2\n", player1);
			scanf("%d", &batselect);
		}
		if (batselect == 1)
		{
			printf("\n\n\n**********%s Get ready for Bating**********\n", player1);
			score1 = bating(balls, player1,player2, score2);
			printf("\n\n\n**********%s Get ready for Bating**********\n", player2);
			score2 = bating(balls, player2,player1, score1);
			//printf("%d->score1 & %d-> score2", score1, score2);
			winner(player1, score1, player2, score2);
		}
		else if(batselect == 2)
		{

			printf("\n\n\n**********%s Get ready for Bating**********\n", player2);
			score1 = bating(balls, player2,player1, score1);
			printf("\n\n\n**********%s Get ready for Bating**********\n", player1);
			score2 = bating(balls, player1,player2, score2);
			//printf("%d->score1 & %d-> score2", score1, score2);
			winner(player2, score1, player1, score2);
		}
		
	}
	else if(choose != toss)
	{
		printf("\n%s won the TOSS\n\nSelect....\n1) Bating\t\t\tPress 1\n2) Bowling\t\t\tPress 2\n", player2);
		scanf("%d", &batselect);
		if (batselect == 1)
		{

			printf("\n\n\n**********%s Get ready for Bating**********\n", player2);
			score1 = bating(balls, player2,player1, score1);
			printf("\n\n\n**********%s Get ready for Bating**********\n", player1);
			score2 = bating(balls, player1 ,player2, score2);
			//printf("%d->score1 & %d-> score2", score1, score2);
			winner(player2, score1, player1, score2);
			
		}
		else
		{
			printf("\n\n\n**********%s Get ready for Bating**********\n", player1);
			score1 = bating(balls, player1,player2, score2);
			printf("\n\n\n**********%s Get ready for Bating**********\n", player2);
			score2 = bating(balls, player2,player1, score1);
			//printf("%d->score1 & %d-> score2", score1, score2);
			winner(player1, score1, player2, score2);
		}
	}



}
int bating(int ball, char name[], char bowler[], int scorechecker)
{
	int runs;
	int totruns = 0;
	for (int i = 1; i <= ball; i++)
	{
		if (scorechecker < totruns)
		{
			return totruns;
		}
		delay(3);
		printf("%s is ready to Bowl\n", bowler);
		runs = score(name, bowler);
		if(scorechecker>totruns)
		{
			if (runs == 5)
			{
				totruns += runs;
				ball += 1;
				printf("%s's total Score is %d\n\n",name, totruns);
			}
			else if (runs == 7)
			{
				printf("%s's total Score is %d\n\n",name, totruns);
				break;
			}
			else
			{
				totruns += runs;
				printf("%s's total Score is %d\n\n",name, totruns);
			}
		}

	}
	return totruns;
}
int score(char batsman[],char bowler[])
{
	int scorerun;
	srand(time(0));
	scorerun = rand() % 8;
	switch (scorerun)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		printf("%s took %d score\n",batsman, scorerun);
		break;
	case 4:
		printf("Great Shot!!%s hit the Boundary\n", batsman);
		break;
	case 5:
		printf("Congrats %s....White ball and four runs\n", batsman);
		break;
	case 6:
		printf("What a Shot!! %s Good sixer\n", batsman);
		break;
	case 7:
		printf("OOPs !! %s is out\n%s took the wicket__well Done %s\n\n", batsman, bowler, bowler);
		break;
	}
	return scorerun;
}
void winner(char *name1, int sc1 , char *name2, int sc2)
{
	if (sc1 > sc2)
	{
		//getchar(); 
		printf("\t\t\t~~~~~~~~~~CONGRATULATIONS~~~~~~~~~~\t\t\t");
		//printf("YOU WON 1");
		printf("\n%s won the Match %s Better luck next time", name1, name2);
		printf("\nScore of %s is %d and Score of %s is %d", name1, sc1, name2, sc2);
	}
	else if (sc1 < sc2)
	{
		//getchar();
		printf("\t\t\t~~~~~~~~~~CONGRATULATIONS~~~~~~~~~~\t\t\t");
		//printf("YOU WON 2");
		printf("\n%s won the Match %s Better luck next time", name2, name1);
		printf("\nScore of %s is %d and score of %s is %d", name1, sc1, name2, sc2);
	}
	else if(sc1 == sc2)
	{
		printf("\t\t\t~~~~~~~~~~Match is DRAWN~~~~~~~~~~\t\t\t");
		printf("\nScore of %s is %d and score of %s is %d", name1, sc1, name2, sc2);
	}
}