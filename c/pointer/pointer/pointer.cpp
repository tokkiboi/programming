#include <stdio.h>
#include <stdlib.h>

void SetNewValues(int* array, int n);
void sort(int** ptrArray, int num_of_readings);

int main(void)
{
	int a = 1;
	int i;
	int array[3] = {1, 3, 2};
	int** ptrarray;
	ptrarray = (int**)calloc(3, sizeof(int*));
	printf("%d\n", a);
	printf("%p\n", &a);
	for(i=0;i<3;i++)
	{
		printf("array: %d\n", array[i]);
	}
	for(i=0;i<3;i++)
	{
		*(ptrarray+i) = &array[i];
		printf("ptrarray: %p\n", ptrarray[i]);
	}
	sort(ptrarray, 3);
	for(i=0;i<3;i++)
	{
		printf("sortedarray: %d\n", **(ptrarray+i));
	}

	SetNewValues(array, 3);
		for(i=0;i<3;i++)
	{
		printf("newvalur arary: %d\n", array[i]);
	}
	sort(ptrarray, 3);


	system("pause");
	return 0;

}

/*=================================*/

void SetNewValues(int* array, int n)
{
	*(array+0)=4;
	*(array+1)=6;
	*(array+2)=5;
	return;
	
}

/*=============================================*/
void sort(int** ptrArray, int num_of_readings)
{
	int current;
	int walker;
	int smallest_index;
	int temp;
	for(current=0;current<num_of_readings-1;current++)
	{
		smallest_index = current;
		for(walker = current; walker < num_of_readings; walker++)
		{
			if(**(ptrArray + walker) < **(ptrArray + smallest_index))
			{
				smallest_index = walker;
			}

			
		}
		temp = **(ptrArray+current);
		**(ptrArray + current) = **(ptrArray + smallest_index);
		**(ptrArray  +smallest_index) = temp;
		
	}
	return;
}
