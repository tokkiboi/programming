#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* array;
	int i;
	char **  ptrarr;

	array = (char*)calloc(3, sizeof(char));
	*(array+0) = 'A';
	*(array+1) = 'M';
	*(array+2) = 'M';
		
	/*ptrarr = (char**)calloc(3, sizeof(char**));
	**(ptrarr+0) = *(array+0);
	**(ptrarr+1) = *(array+1);
	**(ptrarr+2) = *(array+2);*/
	
	for(i=0;i<=2;i++)
	{
		printf("%c", *(array+i));
	}
	printf("\n");

	/*for(i=0;i<=2;i++)
	{
		printf("%c", **(ptrarr+i));
	}
	printf("\n");*/

	system("pause");
	return 0;
}