#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 4

int sumCol(int [][MAX_COL], int rows, int col); // 0 based



int main(void)
{
	int A[][MAX_COL]={
						{1,2,3,13},
						{4,5,6,16},
						{7,8,9,19}
					 };

	int** ptrA;
	int r=3; int c=MAX_COL;
	int i; int j;

	for (i = 0; i< r; i++)
	{
		for(j = 0; j < c; j++)
			printf(" %5d", *(*(A + i) + j));
		printf("\n");
	}
	printf("\n");
	printf("%d  %d\n", A, **A);
	for (i = 0; i< r; i++)
	{
		for(j = 0; j < c; j++)
			printf(" %5d", ((A + i) + j));
		printf("\n");
	}

	printf("\n Sum is %d: ", sumCol(A, 3, 2));
	printf("\n\n\n");
	printf("Author: Amrita Mukherjee\n");

	system("pause");
	return 0;
}
/*========================SumCol====================*/

int sumCol(int A[][MAX_COL], int rows, int col)
{
	int sum = 0;
	int row;
	
	for(row = 0; row < rows; row++)
	{
		sum += *(*(A + row) + col);		
	}
	return sum;
}


/* My Test Session:
     1     2     3    13
     4     5     6    16
     7     8     9    19

3800680  1
 3800680 3800696 3800712 3800728
 3800696 3800712 3800728 3800744
 3800712 3800728 3800744 3800760

 Sum is 18:


Author: Amrita Mukherjee
Press any key to continue . . .
*/