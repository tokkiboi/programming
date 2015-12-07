#include <stdio.h>
#include <stdlib.h>

/* *7.  Write a function to rank (in a separate array) a set of n integer scores from low to high.  For 
instance, array[order[0]] should contain the smallest value. */

void rankArrayLowToHigh(int array[], int n);

int main(void)
{
	int array[] = {2,5,3,1,6,9,7,6};
	int n=8;
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	rankArrayLowToHigh(array, 8);
	for(i=0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}




/*=======rankArrayLowToHigh(Selection Sort)====================*/
/*void rankArrayLowToHigh(int array[], int n)
{
	int i;
	int j;
	int smallest;
	int temp;
	
	for(i=0; i<=n-2; i++)
	{
		smallest = i;
		for(j=i+1; j<=n-1;j++)
		{
			if(array[j]<array[i])
			{
				smallest = j;
			}
		}
		temp = array[smallest];
		array[smallest] = array[i];
		array[i] = temp;

	}
	return ;
}
*/



/*=======rankArrayLowToHigh(Bubble Sort)====================*/
void rankArrayLowToHigh(int array[], int n)
{
	int i;
	int j;
	int smallest;
	int temp;
	
	for(i=0; i<=n-2; i++)
	{
		smallest = i;
		for(j=i+1;j<=n-1;j++)
		{
			
			if(array[j]<array[i])
			{
				smallest = j;
			
			}
		}
		temp = array[smallest];
		array[smallest] = array[i];
		array[i] = temp;
	}
	return ;
}