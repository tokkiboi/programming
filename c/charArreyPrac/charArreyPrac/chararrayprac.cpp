#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* array, int len);

int main(void)
{
	char array1[10];
	char array2[10];

	int l1, l2;
	strcpy(array1, "Mary");
	strcpy(array2, "Mary ");

	l1 = strlen(array1);
	l2 = strlen(array2);
	reverse(array1, l1);
	reverse(array2, l2);
	printf("rev array1 \"%s\"\n", array1);
	printf("rev array2 \"%s\"\n", array2);
	return 0;
}

/*================================*/

void reverse(char* array, int len)
{
	int i = 0;
	int j = len-1;
	char temp;
	
	while(i<j)
	{
		temp = *(array + j);

		*(array + j) = *(array + i);
		*(array + i) = temp;
		i++;
		j--;


	}
	return;

}