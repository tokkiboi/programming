#include <stdio.h>
#include <stdlib.h>
# define MAX_QUESTION 100
# define MAX_STUDENT 50
int input(FILE* fp, int pins[], int student_scores[], float percentage_correct[]);
void sort(int student_scores[], int no_of_students, int pin[], float percentage_correct[]);
void output(int pins[], int student_scores[], float percentage_correct[], int no_of_students);
/*LAB #1
Amrita Mukherjee
email - m.amrita@gmail.com
Mini-Scantron
Write a program that will grade the results of a true/false test and display the results in a table.  
The first line of the data file is the number of questions on the test.  Assume a maximum of 100 
questions. The second line contains the characters representing the correct answers or ‘key’. 
Following these first two lines will be lines containing a pin number and responses from each 
student. Quit input when EOF is reached. Assume a maximum of 50 students.
Sample data file:
5
TTTFF
9234 FFFTT
2345 TTTTT
4567 FFFFF
Your program should input the number of questions and store the key in an array of char. It 
should then read the remaining lines, storing the student pin number in one integer array and the 
number of correct responses in a parallel integer array. Do not attempt to store the student 
answers in an array. Rather, see if the response matches the correct answer and then continue 
with the next response.
Output should be 3 columns: one for the student identification number, one for the number of 
correct responses, and one for the percentage correct. These should be sorted in ascending order 
by the pin number using a selection sort. This output should be directed to a file.
Theme Issues:  Functions, one-dimensional arrays, sorting
*/

int main(void)
{
	
	int pins[MAX_STUDENT];
	int student_scores[MAX_STUDENT];
	float percentage_correct[MAX_STUDENT];

	int no_of_students;
	FILE * fp;
	fp = fopen("labCount.txt", "r");//open file in read mode
	
	no_of_students = input(fp, pins, student_scores, percentage_correct);//input function returns total number of students
	sort(student_scores, no_of_students, pins, percentage_correct );//this function sorts scores of all students from highest to lowest
	output(pins, student_scores,  percentage_correct,  no_of_students);// this function prints the output in a file
	fclose(fp);//file close
	system("pause");
	return 0;
		
}
/*=====================================input============================================================*/
/*
this function reads the file using file handle and populate the array for pin number, student score and calculates the correct percentage for each student
and returns total number of students
Pre: FILE* fp, int pins[], int student_scores[], float percentage_correct[]
POst: no_of_students
*/
int input(FILE* fp, int pins[], int student_scores[], float percentage_correct[])
{
	int no_of_students = 0;
	int num_of_question;
	char correctAnswers[MAX_QUESTION+1];

	int i, j;
	char answer[MAX_QUESTION+1];

	fscanf(fp, "%d", &num_of_question);//reads first line and gets the number of quesstions
	fscanf(fp, "%s", correctAnswers);//reads second line and gets the correct answer
	
	i = 0;
	while((fscanf(fp, "%d %s", pins+i, answer)) == 2)
	{
		int score = 0;
		// How many of then are right? 
		for(j=0;j<num_of_question;j++)
		{
			if(correctAnswers[j]==answer[j])
			{
				score = score + 1;//calculates right answer for each student
			}
		}
			
		student_scores[i]=score;//stores the score for each student in an array
		percentage_correct[i] = ((float)score/num_of_question)*100;// calculates percentage correct
		no_of_students++;//calculates total number of students
		i++;
	}
	return no_of_students;

}
/*=========================sort=========================================================================*/
/*this function sorts the array in decending order
Pre: int student_scores[], int no_of_students, int pin[], float percentage_correct[] 
POst: no_of_students
*/
void sort(int student_scores[], int no_of_students, int pin[], float percentage_correct[] )
{
	int current; int walker;
    int largestIndex;
    int temp;
	float tempfloat;
    
    for (current = 0; current < no_of_students - 1; current++)
    {
        largestIndex = current;
        for (walker = current; walker < no_of_students; walker ++)
          {
                if (student_scores[walker] > student_scores[largestIndex])
                  largestIndex = walker;
          }//for walker
      
        //Swap to position largest at what is the current position
        temp = student_scores[current];// for student scores
        student_scores[current] = student_scores[largestIndex]; 
        student_scores[largestIndex] = temp; 

		temp = pin[current];//swap position for pins
		pin[current] = pin[largestIndex];
		pin[largestIndex] = temp;

		tempfloat = percentage_correct[current];//swap position for percentage correct
		percentage_correct[current] = percentage_correct[largestIndex];
		percentage_correct[largestIndex] = tempfloat;
    }//for current 
  return;
}

/*=========================output============================================*/
/*this function prints output in a file
Pre: int pins[], int student_scores[], float percentage_correct[], int no_of_students
POst: no_of_students
*/
void output(int pins[], int student_scores[], float percentage_correct[], int no_of_students)
{
	FILE* fp;
	int i;
	fp = fopen("output.txt", "w");//open file in write mode
	fprintf(fp, "Lab1 | Amrita Mukherjee | email:m.amrita@gmail.com\n");
	fprintf(fp, "Pin   Score  PercentageCorrect\n");//prints the heading
	for(i=0;i<no_of_students;i++)
	{
		
		fprintf(fp, "%-4d  %-4d   %-4.2f\n", pins[i], student_scores[i], percentage_correct[i]);//prints pin no, student score and percentage score in decending order
	}
	fclose(fp);//close file
	
	return;

}
/*
MY Test session:
Pin   Score  PercentageCorrect
5750  2      33.33
4173  3      50.00
5120  3      50.00
7563  5      83.33
2315  3      50.00
8481  5      83.33
5826  4      66.67
4392  4      66.67
3890  4      66.67
9412  3      50.00
9423  2      33.33
8621  3      50.00
9905  1      16.67
9060  3      50.00
9811  0      0.00
*/

