#include <stdio.h>
#include <stdlib.h>

#define MAX_SCORE 100

/*Write a program to save room for a maximum of 100
scores.

Prompt the user for the number of scores and input
the number of scores. Then input each score from the user. 
Compute the mean and the standard deviation.
Output the mean and standard deviation to the
screen and then copy your output as a comment at the bottom of the course code.
Your name needs to appear as a comment in the
source code AND printed to the output using a printf() statement.
Copy and paste your source code with the output
to the assignment in Catalyst.
You only get one try and cannot change your
submission. The cutoff time is enforced. Please note that I made this simpler
since you do not have to input from a file.   */

int main(void)
{
	int sum =0;
	int score;
	int n;
	int i;
	float mean;
	int score_sq;
	int total_score_sq = 0;
	float standard_deviation;
	float numMinusMeanSq;
	float Total_numMinusMeanSq = 0;
	int array[MAX_SCORE];

	printf("Please enter total number of scores\n");
	scanf("%d", &n);
	printf("Please enter the scores: \n");
	for(i=0; i<n;i++)
	{
		scanf("%d", &array[i]);
		sum = sum+array[i];
		//printf("\n");

	}
	mean = (float)(sum/n);
	for(i=0;i<n;i++)
	{
		numMinusMeanSq = (float)(array[i] - mean) * (float)(array[i] - mean);
		Total_numMinusMeanSq = Total_numMinusMeanSq + numMinusMeanSq;
	}
	standard_deviation = (float)(Total_numMinusMeanSq/n);
	
	printf("mean : %.2f\n", mean);
	printf("standard deviation : %.2f\n", standard_deviation);
	system("pause");
	return 0;
}

/* my test session :
Please enter total number of scores
3
Please enter the scores:
1
2
3
mean : 2.00
standard deviation : 0.67
Press any key to continue . . .
*/
