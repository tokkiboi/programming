/*	Group project(must complete with one or two other students)
	Submit hardcopy of source code and output Monday, Nov 19*/
// __Amrita Mukherjee______________________
// ________________________

//Alphabetizing using strings
/*	Step 1. Run the program as is.*/
/*	Step 2. Declare an array called id[] for the student ID numbers and
	another array sc[] for the scores. Add sscanf() statement after
	fgets()to input each student ID number into id[], the name temporarily
	into tempName[] and the score into sc[]. Be sure to count the number
	of students.*/
/*	Step 3. Declare an array of pointers to char called name[]. Add
	necessary statements to allocate memory for each name and copy the
	name into that allocated memory storing the pointer in name[].*/
/*	Step 4. Add an output function called from main to output all data.*/
/*	Step 5. If all is working well delete the puts() statement.
/*	Step 6. Write a sort routine to sort by the names. Call this
	function from main() just before calling the output function*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 70

void sortSelect(char* name[], int id[], float sc[], int studentNum);
void output(int* id, char** name, float* sc, int studentNum);



int main (void)
{
	FILE* fpIn;

	char buffer[256];
	char tempName[81];
	int id[MAX_STUDENTS];
	float sc[MAX_STUDENTS];
	int studentNum;
	char* name[MAX_STUDENTS];
	char* newname;

	char* pbuf;//might need since sscanf does not move pointer down

	if(!(fpIn=fopen("data.txt","r")))
	{
		printf("\nInput file cannot be opened");system("pause");
		return 100;
	}

	studentNum=0;
	while (!feof(fpIn))
	{
		fgets(buffer,sizeof(buffer)-1,fpIn);
		sscanf(buffer, "%d%*c%[^1234567890.]%f", &id[studentNum], tempName, &sc[studentNum]);
		if(tempName[strlen(tempName)-1] == ' ')
		{
			tempName[strlen(tempName)-1] = '\0';
		}
		name[studentNum]=(char*)calloc(strlen(tempName)+1, sizeof(char));
		strcpy(name[studentNum],tempName);
		studentNum++;
	}
	sortSelect(name, id, sc, studentNum);
	output(id, name, sc, studentNum);


	system("pause");
	return 0;
}

/*==============sortSelect====================*/
void sortSelect(char* name[], int id[], float sc[], int studentNum)
{
	int current; int walker;
	int smallestIndex;
	char* temp;
	int tempint;
	float tempfloat;

	for (current = 0; current < studentNum - 1; current++)
	{
		smallestIndex = current;
		for (walker = current; walker < studentNum; walker ++)
		{
			if (strcmp(name[walker], name[smallestIndex]) <0)
			smallestIndex = walker;
		}//for walker

		//Swap to position smallest at what is the current position
		temp = name[current];
		name[current] = name[smallestIndex];
		name[smallestIndex] = temp;

		tempint = id[current];
		id[current] = id[smallestIndex];
		id[smallestIndex] = tempint;

		tempfloat = sc[current];
		sc[current] = sc[smallestIndex];
		sc[smallestIndex] = tempfloat;

	}//for current
	return;
}
/*================output==================*/

void output(int* id, char* name[], float* sc, int studentNum)

{
	int i;
	for(i=0;i<studentNum;i++)
	{
		printf("%d ***%s*** %.2f\n", id[i], name[i], sc[i]);
	}

	return;
}

/*
	My test session:
	7823 ***CYNTHIA LI*** 99.20
	2456 ***HENRY PAT NIXON*** 89.50
	1123 ***RYAN B ANTHONY*** 78.90
	3356 ***TOM H ADAMS*** 67.90
	'\\puma\home\mamrita\visual studio 2010\Projects\new\new'
	CMD.EXE was started with the above path as the current directory.
	UNC paths are not supported.  Defaulting to Windows directory.
	Press any key to continue . . .
*/