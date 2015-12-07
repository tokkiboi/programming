#include <stdio.h>
#define MAX 50
#define LEN 20

void names(void)
{
	printf("\n Programming Pair:\n 1. XXXXXXXXXX \n 2. XXXXXXXXXXX\n\n");
}


int getData(FILE*, char[], float[],char[][]);
void selectSort(char[], float[],char[][], int);
void output(char[], float[],char[][], int);

int main(void)
{
	FILE* fpIn;
	char grades[MAX];
	float percent[MAX];
	char nom[MAX][LEN];
	int numStu = 0;

	if ((fpIn = fopen("grades.txt","r"))==NULL)
	{
		printf("\nNo such file"); return 0;}

	numStu = getData(fpIn, grades, percent, nom);

	output ( grades, percent, nom, numStu);

	return 0;
}

int getData(FILE* fpIn, char grade[], float percent[], char nom[][])
{
	int i = 0;
	int j;

	while (i < MAX && fscanf(fpIn," %c", &grade[i])!=EOF)
	{
		fscanf(fpIn, "%f%*c", &percent[i]);

		j = 0;
		while(j < LEN && (nom[i][j] = fgetc(fpIn)) != '\n')
			j++;

		i++;
	}//while i
	return i; //number of students
}

void output(char grade[], float percent[], char nom[][], int numStu)
{
	int i; int j;
	names();
	for (i = 0; i < numStu; i++)
	{
		for (j = 0; j< LEN; j++)
			printf("%c", nom[i][j]);
		printf("   %5.1f%3c\n",percent[i], grade[i]);
	}
	return;
}//output



