#include <stdio.h>
#include <stdlib.h>


void reverse(int* array, int len);

int main(void)
{
	int arr[] = {45,67,89,4,3,101};
	int len = 6;
	int i =0;

	reverse(arr, len);
	for(i=0; i<len;i++)
	{
		printf(" %d", arr[i]);
	}
	
	
	return 0;
}

/*================================*/

void reverse(int* array, int len)
{
	int i = 0;
	int j = len-1;
	int temp;
	
	while(i<j)
	{
		temp = *(array+j);

		*(array+j) = *(array+i);
		*(array+i) = temp;
		i++;
		j--;


	}
	return;

}