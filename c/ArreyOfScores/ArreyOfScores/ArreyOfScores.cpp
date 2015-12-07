#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define MAX_SCORES 100

/* Write a program to save room for a maximum of 100 scores.

Prompt the user for the number of scores and input the number of scores. Then input each score from the user. 

Compute the mean and the standard deviation.
*/


int main(void)
{
	int score;
	int sum = 0;
	int array[MAX_SCORES];
	float mean;
	int i;
	int num_of_scores;
	int square_score;
	int sum_square_score = 0;
	float standard_deviation;

	printf("Please enter total number of scores: ");
	scanf("%d", &num_of_scores);
	//printf("Please enter the numbers: ");
	//scanf("%d", &score);
	
	for(i=0; i< num_of_scores; i++)
	{
		
		printf("Please enter the numbers: ");
		scanf("%d", &score);
		//array[i] = score;
		//sum += array[i];
		sum += score;
		square_score = score*score;
		sum_square_score += square_score;

	}
	mean = (sum/num_of_scores);

	standard_deviation = sqrt((float)(sum_square_score/(num_of_scores-1)));
	printf("Mean is %.2f\n", mean);
	printf("Standard deviation is %.2f\n", standard_deviation);

	system("pause");
	return 0;
		

}
/*
My Test Session:
Please enter total number of scores: 3
Please enter the numbers: 1
Please enter the numbers: 2
Please enter the numbers: 3
Mean is 2.00
Standard deviation is 2.65
Press any key to continue . . .
*/