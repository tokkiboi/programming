#include <stdio.h>
#include <stdlib.h>
#define MAX_DIVER 50
#define MAX_NAMELENGTH 20
#define N_JUDGES 5
int input(FILE* fp, char name[MAX_DIVER][MAX_DIVER], float score[MAX_DIVER][N_JUDGES], float difficulty[MAX_DIVER]);
void sort(float score[MAX_DIVER][N_JUDGES], int diverid);
void calculatescore(float score[MAX_DIVER][N_JUDGES], int diverid, float difficulty[MAX_DIVER], float totalScore[MAX_DIVER]);
void output(char name[MAX_DIVER][MAX_DIVER],float score[MAX_DIVER][N_JUDGES],float totalScore[MAX_DIVER], int diverid);

/*
Lab2
Author : Amrita Mukherjee
email : m.amrita@gmail.com
CIS 15BG
LAB #2

Scoring a Diving Competition 

The names of divers and their scores for a dive are stored in a file called DIV1.txt .  Each diver's name is 20 characters long followed by the difficulty factor of
the dive and a score from each of 5 judges.  Compute each diver’s total score by throwing out his/her low and high scores, averaging the remaining three scores, and
then multiplying this average by the difficulty factor.  Output each diver's name, his/her 3 middle scores from low to high, and the total score for the dive arranged
from the diver with the highest score to the lowest. Output is to be directed to a file.

The contents of DIV1.txt is to be:

   KNIFE JACK          1.3 6.0 5.1 6.3 5.9 6.5
   WILLIAMSON FLIP A   1.4 3.5 4.1 4.7 7.2 3.8
   SOMMER TODD         1.2 8.0 9.1 8.1 9.3 9.0
   SWAN MIKE           1.1 4.3 2.1 9.9 6.2 7.0

Assume a maximum of 50 divers.  The program needs to be well-modularized including a separate function for input, a separate function for output, and at least two other
functions in addition to main.  All functions need to include Pre and Post. (See coversheet)

Theme Issues:	1 and 2-dimensional arrays;
		Sorting

No string functions may be used including no %s.

*/
int main(void)
{
	FILE* fp;
	char name[MAX_DIVER][MAX_DIVER];
	float score[MAX_DIVER][N_JUDGES];
	float difficulty[MAX_DIVER];
	int divercount;
	float totalScore[MAX_DIVER];
	int i;
	int j;

	fp = fopen("DIV1.txt", "r");//open file in read mode
	if (fp == NULL)
	{
		return 1;
	}
	divercount = input(fp, name, score, difficulty);// this function reads data from input file and calculates the total number of diver
	sort(score, divercount);//this function sorts socres from each diver
	calculatescore(score, divercount, difficulty, totalScore);// this function calculates total score for each diver
	output(name, score, totalScore, divercount);// this function prints output in a file
	
	system("pause");
	return 0;
}
/*==========================================input========================================================================================*/
/*
this function reads data from input file and calculates the total number of diver
pre:FILE* fp, char name[MAX_DIVER][MAX_DIVER], float score[MAX_DIVER][N_JUDGES], float difficulty[MAX_DIVER]
post: int diverid
*/
int input(FILE* fp, char name[MAX_DIVER][MAX_DIVER], float score[MAX_DIVER][N_JUDGES], float difficulty[MAX_DIVER])
{
	int ch;
	int i;
	int diverid = 0;

	while (1)
	{
		for (i=0; i<MAX_NAMELENGTH; i++)
		{
			ch = fgetc(fp);// readging character by character
			if(ch == EOF)
			{
				break;
			}
			name[diverid][i] = ch;//populating name array
		}
		if (i != MAX_NAMELENGTH) {
			break;
		}
		fscanf(fp, "%f", difficulty+diverid);// reading population difficulty level array
		for (i = 0; i<N_JUDGES; i++)
		{
			fscanf(fp, "%f", score[diverid]+i);//reading and population score array
		}
		diverid++;//calculating total number of divers
	}
	return diverid;
}
/*===========================sort=====================================================*/
/*
this function sorts socres from each diver
pre:float score[MAX_DIVER][N_JUDGES], int diverid
post:
*/
void sort(float score[MAX_DIVER][N_JUDGES], int diverid)
{
	int current; int walker;
    int smallestIndex;
    float temp;
	int x;
    for(x=0;x<=diverid;x++)//sorting from lowest to highest
	{
		for (current = 0; current < N_JUDGES - 1; current++)
		{
			smallestIndex = current;
			for (walker = current; walker < N_JUDGES; walker ++)
			  {
					if (score[x][walker] < score[x][smallestIndex])
					  smallestIndex = walker;
			  }//for walker
        
			//Swap to position smallest at what is the current position
			temp = score[x][current];
			score[x][current] = score[x][smallestIndex]; 
			score[x][smallestIndex] = temp;  
		}//for current 
	}
    return;
}
/*====================================calculatescore============================================*/
/*
this function calculates total score for each diver
pre: float score[MAX_DIVER][N_JUDGES], int diverid, float difficulty[MAX_DIVER],float totalScore[MAX_DIVER]
post:
*/
void calculatescore(float score[MAX_DIVER][N_JUDGES], int diverid, float difficulty[MAX_DIVER],float totalScore[MAX_DIVER])
{
	int i;
	int j;
	float addScore = 0;
	
	for(i=0;i<diverid;i++)
	{
		for(j=1;j<N_JUDGES-1;j++)//adding scores 2nd lowest to 2nd highest
		{
			addScore = addScore +  score[i][j];
		}
		totalScore[i] = (addScore/(N_JUDGES-2)) * difficulty[i];//calculation total score
	}
	return;
}

/*==============================output=================================================*/
/*
this function prints output in a file
pre: char name[MAX_DIVER][MAX_DIVER],float score[MAX_DIVER][N_JUDGES],float totalScore[MAX_DIVER], int diverid
post:
*/
void output(char name[MAX_DIVER][MAX_DIVER],float score[MAX_DIVER][N_JUDGES],float totalScore[MAX_DIVER], int diverid)
{
	int i;
	int j;

	FILE* fp;
	fp = fopen("output.txt", "w");//open output file in read mode
	fprintf(fp, "Lab 2 | Amrita Mukherjee | email - m.amrita@gmail.com\n\n");
	fprintf(fp, "name                score score score totalscore\n");
	char ch;

	if (fp==NULL) 
	{
		printf("could not open output.txt for writing\n");
		return;
	}

	for(j=0;j<diverid;j++)
	{
		for (i=0; i<MAX_NAMELENGTH; i++)
		{
			ch = name[j][i];
			fputc (ch, fp);
		}
      
		fprintf(fp, "%-3.1f   %-3.1f   %-3.1f   %4.2f", score[j][1], score[j][2], score[j][3], totalScore[j]);// primting scores from 2nd lowest to 2nd highest and total score
		fprintf(fp, "\n");
	}
	fclose(fp);
 }
/* my test session :
Lab 2 | Amrita Mukherjee | email - m.amrita@gmail.com

name                score score score totalscore
KNIFE JACK          5.9   6.0   6.3   7.89

WILLIAMSON FLIP A  3.8   4.1   4.7   14.37

SOMMER TODD        8.1   9.0   9.1   22.80

SWAN MIKE          4.3   6.2   7.0   27.32
*/

