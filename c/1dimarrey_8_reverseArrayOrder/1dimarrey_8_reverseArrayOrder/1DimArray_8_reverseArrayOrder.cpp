#include <stdio.h>
#include <stdlib.h>

/*  8.  Write a function to accept an array of n integers.  Reverse the order of the elements of the 
array */


void reverse(int array[], int n);

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n =8;
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	reverse(array, 8);
	for(i=0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


/*================reverse==============*/


void reverse(int array[], int n)
{
	
	int i;
	int temp;
	for(i=0; i<n; i++)
	{
		temp = array[i];
		array[i] = array[n-1];
		array[n-1] = temp;
		n--;
	}
	return;
}

/* My test Session:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Press any key to continue . . .
*/
