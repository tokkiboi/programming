#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 10
#define MAX_ROW 10

int fun(float array[MAX_ROW][MAX_COL]);

/*1. Write the necessary statements to declare a two-dimensional array of floats with 50 rows and 25 columns.

2. Write a function to input values for this 2-dimensional array from a file named data.txt. You are guaranteed
25 values per line. Read until end of file. Return the number of rows that data was input for.
*/

int main(void)
{
	int ret;
	//int i;
	float array[MAX_ROW][MAX_COL];
	ret = fun(array);
	printf("return value is : %d\n", ret);
	system("pause");
	return 0;
}
	




int fun(float array[MAX_ROW][MAX_COL])
{
	char input[50];
	FILE* fp;
	int i = 0;
	//int n = 5;
	fp = fopen("mydata.txt", "r");
	while(fscanf(fp, "%s", input[50])!=NULL)
	{
		sscanf(input, "%f %f %f %f %f", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4]);
		i++;
	}
	fclose(fp);
	return i;
}