#include <stdio.h>
#include <stdlib.h>

#define MAXSTUDENT   50
#define MAXQUESTIONS 100
#define PINLENGTH    20
#define MAXLINELENGTH MAXQUESTIONS+PINLENGTH

char dataFileName[] = "lab1.txt";

void readStudentData(char dataFileName[],
                     int studentPins[],
                     int studentScores[]);
void sortByPin(int studentPins[], int studentScores[], int studentCount);

int main(void)
{
    int studentPins[MAXSTUDENT];
    int studentScores[MAXSTUDENT];
        int i;
        int studentCount;
    printf("This program written by: Amrita Mukherjee\nEmail: m.amrita@gmail.com\nLab1\n");
    readStudentData(dataFileName, studentPins, studentScores);
    i = 3;
    sortByPin(studentPins, studentScores, studentCount);
    //generateScoreChart(studentPins, studentScores);
    return 0;
}

void readStudentData(char dataFileName[],
                     int studentPins[],
                     int studentScores[])
{
    FILE *fp = NULL;
    char line[MAXQUESTIONS+PINLENGTH];
    int  numberOfQuestions;
    char correctAnswerString[MAXQUESTIONS];
    int  studentCount;

    int i;
    int pin;
    char answer[MAXQUESTIONS+1];
    int score;

    fp = fopen(dataFileName, "r");
    if (fp == NULL) {
        printf("Could not open file %s for reading. Aborting...\n", dataFileName);
		system("echo The current directory is: %CD%");
        exit(1);
    }

    // Total number of questions
    fgets(line, MAXLINELENGTH, fp);
    sscanf(line, "%d", &numberOfQuestions);

    // Read correct answers
    fgets(line, MAXLINELENGTH, fp);
    sscanf(line, "%s", correctAnswerString);

    // Read answers for each student
    studentCount = 0;
    while ( (studentCount <= MAXSTUDENT) &&
            (fgets(line, MAXLINELENGTH, fp) != NULL)
          )
    {
        studentCount++;
        sscanf(line, "%d %s", &pin, answer);
        score = 0;
        for (i = 0; i < numberOfQuestions; i++) {
            if (correctAnswerString[i] == answer[i]) {
                score++;
            }
        }

        studentPins[studentCount-1] = pin;
        studentScores[studentCount-1] = score;
    }


}

void sortByPin(int studentPins[], int studentScores[], int studentCount)
{
    int current;
    int smallestIndex;
    int temp;
    int walker;

    for(current = 0; current < studentCount-1; current++)
    {
      smallestIndex = current;
      for(walker = current; walker<studentCount; walker++ )
      {
          if (studentPins[walker] < studentPins[smallestIndex])
            smallestIndex = walker;
      }
      temp = studentPins[current];
      studentPins[current] = studentPins[smallestIndex];
      studentPins[smallestIndex] = temp;
    }
    printf("%d\n", studentPins);
    return;
}
