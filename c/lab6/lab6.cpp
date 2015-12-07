#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 20
#define LINE_LENGTH 200

typedef struct skater{
                       char  name[NAME_LENGTH];
                       float baseValue[8];
                       int   scores[8][12];
                       float totalScore;
                     }SKATER;

int getData(SKATER** ptr_skatersArray, char* eventName);
void output(SKATER* skaters, int n_skaters, char* eventName );
void sortInt(int* firstInt, int n);
void calculateScore(SKATER* skaterData);
void sortByTotalScore(SKATER* ptr_firstSkater, int n_skaters );


/*
Author : Amrita Mulherjee
lab6
12/3/2012

ISU Figure Skating Judging System

Write a 'C' program to compute technical score for the new International Skating Union Figure Skating scoring system.

Input: 
All input is to be from a file. The first line will identify the event. After that there will be a sequence of lines where
the first line contains the name of the skater. Then the next eight lines will contain the element number, base value for this 
element, and then the scores (grades of execution GOE) for that element. These nine lines are repeated for each skater.

The data must be stored as an array of structures where there is one structure for each skater. Each structure must contain

    1. the skaters name (array of char), 
    2. an array of floats for the base values,
    3. a two dimensional array containing the scores for each
       element where there is a row for each element,
    4. and the total score for the skater.

See sample below.

PLUSHENKO Evgeni
1 13.0 0 2 1 1 1 0 1 0 1 1 1 1 
2  7.5 1 2 2 2 2 1 2 1 2 2 2 2
3  6.0 2 1 1 1 1 0 0 2 1 2 1 2
4  2.3 2 1 1 1 1 1 2 1 1 1 1 1
5  3.4 2 2 2 2 1 2 3 3 2 3 2 1
6  2.1 1 1 1 2 2 0 0 0 1 2 1 1
7  3.1 1 0 2 2 1 1 1 2 2 2 2 1
8  3.5 1 1 2 2 1 1 1 1 2 2 1 1

Compute: 
For each element throw out the high and low score for the element, sum the rest and divide by the number of remaining judges. If the base
value for this element is greater than 3.1, then add the result to the base value. Otherwise, if the base value is less than or equal to 3.1,
then add one-half the result to the base value.

Output:
Identify the event at the top of the output. Identify yourself as the "Chief Accountant". Then list each skater's name. Then for each skater 
list each element's base value, GOEs, score on that element. At the end of the skater's list of elements output the sum of the base values and
his/her total technical score. 

The skaters should be sorted from the highest score to the least.

Theme issues: 
fgets(), sscanf(), structures

*/

int main(void)
{
	SKATER* skaters;
	int n_skaters;
	char eventName[200];
	
	n_skaters = getData(&skaters, eventName);//get data from file and calculates total number of skaters
	sortByTotalScore(skaters, n_skaters);//sotrs by totalscore from highest score to lowest
	output(skaters, n_skaters, eventName);//prints the output in a file
	
	system("pause");
	return 0;
}

/*============getData===========================================================================*/
/*
pre : pointer to the structure
post : 1. returns number of skaters n
       2. allocates n elements of SKATER and assigns that pointer to the allocated array 
	      to ptr_skatersArray.
*/
int getData(SKATER** ptr_skatersArray, char* eventName)
{
    FILE* fp;
	char line[LINE_LENGTH];
	int num_of_skaters;
	int skater_index;
	int element_id;
	
   
    fp = fopen("data.txt", "r");// open file in read mode
    
	int i =0;
	
	while (!feof(fp))//calculates total number of skaters
		{
		fgets (line , LINE_LENGTH , fp);
		i++;
		}
	num_of_skaters = (i-1)/9;//total number of skaters
	
    fclose(fp);//close file
	*ptr_skatersArray=(SKATER*)calloc(num_of_skaters, sizeof(SKATER));// allocates momery
	fp = fopen("data.txt", "r");//open file again in read mode
	fgets(eventName , LINE_LENGTH , fp);//gets event name
	for(skater_index=0;skater_index<num_of_skaters;skater_index++)
	{
		SKATER* my_skater_struct_ptr;
		my_skater_struct_ptr = (*ptr_skatersArray)+skater_index;

		fgets(my_skater_struct_ptr->name, LINE_LENGTH, fp);//gets name of skaters
		for(element_id=0; element_id<8; element_id++)
		{
			int (*myscores)[12];
			int throwaway;
			fgets(line, LINE_LENGTH, fp);
			//2  7.5 1 2 2 2 2 1 2 1 2 2 2 2
			myscores = my_skater_struct_ptr->scores;
			sscanf(line, "%d %f %d %d %d %d %d %d %d %d %d %d %d %d", &throwaway, &((my_skater_struct_ptr->baseValue)[element_id])//reads element id
																	, &(myscores[element_id][0]), &(myscores[element_id][1]), &(myscores[element_id][2]), &(myscores[element_id][3])
																	, &(myscores[element_id][4]), &(myscores[element_id][5]), &(myscores[element_id][6]), &(myscores[element_id][7])
																	, &(myscores[element_id][8]), &(myscores[element_id][9]), &(myscores[element_id][10]), &(myscores[element_id][11])
																	);//reads score for skaters
			//system("pause");
		}

		calculateScore(my_skater_struct_ptr);//calculater total score for each skaters
	}

	return num_of_skaters;
}

/*==================print_skatersArray=================================================================================================================*/
/*
pre : pointer to the structure, total number of shaters, eventname
post : output prints in a file, event name, base scores, scores, calculates and prints total base score and total score
*/
void output(SKATER* skaterArray, int n_skaters, char* eventName )
{
	int i;
	int j;
	int k;
	float sum_of_baseValue = 0;
	FILE* fp;
    

    fp = fopen("lab6Output.txt", "w");//opens a file in write mode
    if (fp == NULL)
    {
        printf("I couldn't open results.dat for writing.\n");
        exit(0);
    }
	fprintf(fp, "Eventname : %s\n", eventName);// prints eventname in a file
    fprintf(fp, "Chief Accountant : Amrita Mukherjee\n");// prints name in a file
	SKATER* skater;
	for(i=0;i<n_skaters;i++)
	{
		skater = skaterArray+i;
		fprintf(fp, "===================================================\n");
		fprintf(fp, "Name: %s\n", skater->name);//prints name of skater
		
		for (j=0;j<8;j++)
		{
			sum_of_baseValue = sum_of_baseValue + (skater->baseValue)[j];// adds base value
			
		}
		fprintf(fp, "\n");
		fprintf(fp, "baseValues and  scores\n");
		for(j=0;j<8;j++)
		{
			
			fprintf(fp, "%8.2f", (skater->baseValue)[j]);//prints base value
			for(k=0;k<12;k++)
			{
				fprintf(fp, "%4d", (skater->scores)[j][k]);//prints score
			}
			fprintf(fp, "\n");

		}
		fprintf(fp, "\n");
		fprintf(fp, "Sum of base values : %.2f\n\n", sum_of_baseValue);//prints sum of base value
		fprintf(fp, "TotalTechnicalScore : ");
		fprintf(fp, "%.2f\n\n\n", (skater->totalScore));//prints total score
	}
	fclose(fp);// file close
    return;

}


/*==================sortInt===============================================*/
/*
This function sorts the array from smallest to highest
pre : array of integer and total number of element in the array
post : 
*/
void sortInt(int* firstInt, int n)
{
	int current;
	int walker;
    int smallestIndex;
    int temp;

	for (current = 0; current < n -1; current++)
    {
        smallestIndex = current;
        for (walker = current; walker < n; walker++)
          {
                if (*(firstInt+walker) < *(firstInt+smallestIndex))
                  smallestIndex = walker;
          }//for walker
        
        //Swap to position smallest at what is the current position
        temp = *(firstInt+smallestIndex);
        *(firstInt+smallestIndex) = *(firstInt+current);
		*(firstInt+current) = temp;
    }//for current 
}
/*=========================calculateScore=========================================================*/
/*
This function calculates the total score for each skater
pre : pointer to the structure
post : 
*/

void calculateScore(SKATER* skaterData)
{
	int sum;
	int i;
	int j;
	float result;

	skaterData->totalScore = 0.0;
	for(j=0;j<8;j++)
	{
		int element_score[12];
		for (i=0;i<12;i++)
		{
			element_score[i] = (skaterData->scores)[j][i];
		}
		sortInt(element_score, 12);//sorts score for each skaters
		sum = 0;
		for(i=1;i<11;i++)
		{
			sum = sum + element_score[i]; // adds up score for each skater
		}
		result = (float)sum/10;

		if((skaterData->baseValue)[j] > 3.1)
		{
			result = result + (skaterData->baseValue)[j];
		}
		else
		{
			result = result/2 + (skaterData->baseValue)[j];
		}
		skaterData->totalScore += result;//calculates the total score for each skater
	}
}
/*==============================================================================*/
void sortByTotalScore(SKATER* ptr_firstSkater, int n_skaters )
	/*
This function sorts SKATER arraey based on totalScre fr each skaters, from highest to lowest
pre : pointer to the first structure, total number os afaters
post : 
*/
{
	int current; int walker;
    int highest;
    float temp;
	for (current = 0; current < n_skaters -1; current++)
    {
		SKATER temp;
        highest = current;
        for (walker = current; walker < n_skaters; walker ++)
		{
			if ((ptr_firstSkater+walker)->totalScore > (ptr_firstSkater+highest)->totalScore)
			{
				highest = walker;
			}
		}// for walker
        
		//Swap to position highest at what is the current position
		temp = *(ptr_firstSkater+current);
		*(ptr_firstSkater+current) = *(ptr_firstSkater+highest);
		*(ptr_firstSkater+highest) = temp;  
	}//for current 
}
/*==============================================================================================*/

/*
my test session:
Eventname : MENS SHORT PROGRAM//http://www.isufs.org/results/owg2006/OWG06_Men_SP_Scores.pdf

Chief Accountant : Amrita Mukherjee
===================================================
Name: PLUSHENKO Evgeni


baseValues and  scores
   13.00   0   2   1   1   1   0   1   0   1   1   1   1
    7.50   1   2   2   2   2   1   2   1   2   2   2   2
    6.00   2   1   1   1   1   0   0   2   1   2   1   2
    2.30   2   1   1   1   1   1   2   1   1   1   1   1
    3.40   2   2   2   2   1   2   3   3   2   3   2   1
    2.10   1   1   1   2   2   0   0   0   1   2   1   1
    3.10   1   0   2   2   1   1   1   2   2   2   2   1
    3.50   1   1   2   2   1   1   1   1   2   2   1   1

Sum of base values : 40.90

TotalTechnicalScore : 49.90


===================================================
Name: WEIR Johnny


baseValues and  scores
    7.50   2   2   2   2   1   1   1   1   1   2   1   1
   10.00   1   1   1   1   2   0   1   1   1   1   2   1
    3.00   1   1   1   2   1   0   1   1   2   2   2   2
    3.10   1   2   1   2   1   1   0   0   2   1   1   0
    5.50   0  -1   0  -1  -1   0  -1  -1   1  -2  -2  -2
    1.30   1   1   1   2   1   1   1   0   1   1   1   2
    3.10   0   1   1   1   1   0   0   1   2   1   1   1
    3.00  -1   1   1   2   1   0   1   0   2   1  -1   1

Sum of base values : 77.40

TotalTechnicalScore : 40.60


===================================================
Name: SAVOIE Matthew 


baseValues and  scores
    3.00   0   0   0   1   0   0   0   0   0   0   0  -1
    7.50   1   2   2   1   1   1   1   1   1   1   2   2
    9.50   0   1   1   0   0   0   0   0   0   0   1   1
    3.10   1   1   1   1   1   1   0   0   1   1   0   0
    1.90  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3
    2.10   0   0   1   0   1   0   0   1   1   1   1   1
    3.10   0   0   1   0   0   0   1   1   2   0   2   1
    3.00   0   0   1   1   1   0   1   1   1   1   1   1

Sum of base values : 110.60

TotalTechnicalScore : 34.65


===================================================
Name: LYSACEK Evan 


baseValues and  scores
    7.50  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3
   10.00   1   2   2   1   1   1   1   2   0   1   1   1
    3.00   1   2   2   2   1   0   1   2   1   1   1   2
    3.10   1   1   1   1   1   0   0   0   1   0   1   0
    1.70  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3  -3
    2.10   0   0   1   1   1   1   1   1   1   1   1   1
    3.10   0   0   1   1   0   0   1   1   1   1   1   1
    3.50   0   1   1   2   1   1   1   1   1   1   0   1

Sum of base values : 144.60

TotalTechnicalScore : 33.40



*/