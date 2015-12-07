#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 4

int swap(int array[][MAX_COL], int num_of_rows, int x, int y);

/* Write a function that will accept as parameters a
two-dimensional array of MAX columns, an integer representing
the number of rows, and two integers indicating the rows to be 
swapped. Swap these two rows of the two-dimensional array. Return
1 if the swap was successful. Return 0 if the rows to be 
swapped are out of range with respect to the number of rows (second parameter).

*/
int main(void)
{
	int i;
	int j;
	int n=3;
	//int x;
	//int y;
	int ret;

	int array[][MAX_COL] = {{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12}};
					
												
	ret = swap(array, 3, 2, 4);
	printf("return value : %d\n", ret);
	for(i=0; i<n;i++)
	{
		for(j=0;j<MAX_COL;j++)
		{
			printf("%4d ", array[i][j]);
			
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


/*===============================*/
int swap(int array[][MAX_COL], int num_of_rows, int x, int y)
 {
	int temp;
	int col;

	if(x > num_of_rows || x < 0 || y > num_of_rows || y < 0)
		return 0;

	for(col = 0; col < MAX_COL; col++)
	{
		
		//temp = *(*(array+x*MAX_COL)+col);
		//*(*(array + x * MAX_COL)+col) = *(*(array+y*MAX_COL)+col);
		//*(*(array+y*MAX_COL)+col) = temp;

			temp = array[x][col];
			array[x][col] = array[y][col];
			array[y][col] = temp;
		
		//return 1;
			
	}
	return 1;

 }