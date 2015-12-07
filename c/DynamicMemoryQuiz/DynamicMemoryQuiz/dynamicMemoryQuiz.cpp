#include <stdio.h>
#include <stdlib.h>
#define COL 4

int* function(int** array, int n);


/*Write a function that accepts a two-dimensional array and an integer representing the number of rows in the two dimensional array. 
Assume COL columns in the array. Copy the two-dimensional array row by row into a one-dimensional array dynamically allocated on the heap. 
Return the pointer to this dynamically allocated memory.*/

int main(void)
{
	int array[][] = {{1, 2, 3, 4},
		{5, 6, 7, 8},
	{9, 10, 11, 12}};
	int n = 4;
	int oneDimArray[COL*n];
	int i;
	oneDimArray = function(array, 4);
	for(i=0;i<COL*4;i++)
	{
		printf("%d\n", *(oneDimArray+i));
	}
	return 0;


}

/*=========================================*/
int* function(int array[][COL], int n)
{
	//int x = COL*n;
	int oneDimArray[50];
	int i;
	int j;
	oneDimArray = (int*)calloc(n * COL, sizeof(int));
	for(i=0;i<COL;i++)
	{
		for(j=0;j<n;j++)
		{
			oneDimArray[i*j+j]= array[i][j];
		}
	}
	return oneDimArray;
}