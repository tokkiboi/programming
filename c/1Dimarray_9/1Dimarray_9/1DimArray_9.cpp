#include <stdio.h>
#include <stdlib.h>

void removeElement(float array[], int* element_count, int idx);

/*Write a function to accept an array of floats, the address of an integer representing the 
number of values in the array, and an integer representing the subscript of an element to be 
removed from the array. In addition to removing the element, also adjust the number of elements 
in that array. */

int main(void)
{
	int i;
	int n = 6;
	float array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};


	for (i=0;i<n; i++)
	{
		printf("%d: %.2f\n", i, array[i]);
	}
	printf("\n\n");

	removeElement(array, &n, 2);

	for (i=0;i<n; i++)
	{
		printf("%d: %.2f\n", i, array[i]);
	}

	system("pause");
	return 0;
}

/*==============================*/

void removeElement(float array[], int* element_count, int idx)
{
	
	int i;
	for(i = idx; i<*(element_count)-1; i++)
	{
		array[i] = array[i+1];
		
	}
	
	(*(element_count))--;

	return;
}

My test Session:
0: 1.10
1: 2.20
2: 3.30
3: 4.40
4: 5.50
5: 6.60


0: 1.10
1: 2.20
2: 3.30
3: 4.40
4: 5.50
5: 6.60
Press any key to continue . . .