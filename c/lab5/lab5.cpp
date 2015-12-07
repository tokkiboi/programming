
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getdata(char* filename);
void saveword (char* word);
void sortSelect(char* arr[], int counts[], int num);
void output();

/*
CIS 15BG
Author: Amrita Mukherkee
email: m.amrita@gmail.com
LAB #5 Strings

*/

char* hundredWords[100];
int   hundredCount[100];
int foundWords = 0;

int main(void)
{
	int i;
	getdata("lab5.txt"); //reads data from file and creats an array of 100 non repeated words and clounts the number of words
	sortSelect( hundredWords, hundredCount, foundWords);// sorts the words(string comparisn)
	output();//output in a file
	
	system("pause");
	return 0;
}
/*===============getdata================================
This function reads data from file 'filename' and creates an
array.
pre: reads word from a file filename
Post:updates an array with hundres words
*/
void getdata(char* filename)
{
	
	FILE *fp;
	char word[100]; //Memory for the word
	int i;
	int c;
	
	if((fp=fopen(filename, "r"))==NULL)//open the file in read mode
	{
	  printf("Cannot open file.\n");
	  exit(1);
	}

	i = 0;
	while((c = fgetc(fp)) != EOF)
	{		  
		c = tolower(c);//change to lower fonts
		if(    ('a'<= c && c <='z')//if it is a word populate the word array
			|| ('0'<= c && c <='9')
		  )
		{
			word[i] = c;
			i++;
		}
		else
		{
			word[i]= 0;
			if(i != 0)
			{
				saveword(word);
			}
			i=0;
			
		}
	}
	if(i!=0)
	{
		word[i]=0;
		saveword(word);
	}
	fclose(fp);
	return;
}


/*====================saveword============================
This function creates an array woth 100 words and keep trak of repeat words
pre: accepta a character array containing a word
post: returns void but as a side effects updates hundredWords array and the repeat count
as hundredCount.
*/

void saveword (char* word)
{
	
	int wordlen;
	char* nextWord;
	int i;
	int found = 0;

	if(foundWords == 100) //looking for maximum of 100 words
	{
		return;
	}

	for(i=0;i<foundWords;i++)
	{
		if(strcmp(hundredWords[i], word) == 0) //if word is repeared then increment the repeat count
		{
			found = 1;
			hundredCount[i] += 1;
			break;
		}
	}

	if(!found) //allocates memory for new word and add it to the word array
	{
		wordlen = strlen(word);
		nextWord =(char*)calloc(wordlen+1, sizeof(char));
		strncpy(nextWord, word, wordlen);
		hundredWords[foundWords] = nextWord;
		hundredCount[foundWords] = 1;
		foundWords++;
	}
	
	return;
}
/*==============sortSelect==========================
This function sorts an array
Pre: array and number of variable inside the array
post: array is sorted
*/

void sortSelect(char* arr[], int counts[], int num)
{
	int current; int walker;
	int smallestIndex;
	char* temp;
	int tempint;
	
	for (current = 0; current < num - 1; current++)
	{
		smallestIndex = current;
		for (walker = current; walker < num; walker ++)
		{
			if (strcmp(arr[walker], arr[smallestIndex]) <0)
			  smallestIndex = walker;
		}//for walker
		
		//Swap to position smallest at what is the current position
		temp = arr[current];
		arr[current] = arr[smallestIndex]; 
		arr[smallestIndex] = temp; 

		tempint = counts[current];
		counts[current] = counts[smallestIndex]; 
		counts[smallestIndex] = tempint;  
	}//for current 
	return;
}
/*====================output=========================
this function prints output in a file
pre: Uses the global variable int hundredCount, char* hundredWords, int foundwords
post: prints data to a file
*/
void output()
{
    FILE* fp;
	int i;
    
    fp = fopen("lab5Output.txt", "w");//opens a file in write mode
    if (fp == NULL)
    {
        printf("I couldn't open results.dat for writing.\n");
        exit(0);
    }
    fprintf(fp, "Author : Amrita Mukherjee | email : m.amrita@gmail.com | Lab5\n");

	for(i=0;i<foundWords;i++)// prints data
	{
		fprintf(fp, "%3d: %s\n", hundredCount[i], hundredWords[i]);
	}
   
    fclose(fp);
    return;
}
/*=============================================
My test session:
Author : Amrita Mukherjee | email : m.amrita@gmail.com | Lab5
  2: a
  1: an
  1: are
  2: array
  2: as
  2: be
  1: character
  2: characters
  1: complete
  1: dimension
  1: each
  1: easier
  1: element
  1: entities
  1: first
  1: functions
  1: however
  1: in
  1: individually
  2: is
  1: library
  1: make
  1: many
  2: much
  2: of
  2: one
  1: other
  2: problems
  1: processed
  1: represented
  1: require
  1: saw
  1: simpler
  1: some
  1: stored
  4: string
  2: that
  4: the
  1: them
  1: there
  1: this
  1: treating
  1: we
  1: where
  1: will
  3: within
*/

