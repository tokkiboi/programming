#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
author : Amrita Mukherjee
Declare a structure for a student record consisting of five fields:
the student 4-digit pin number, first name (dynamically allocated
string), last name (max of 20 char), number of units completed (integer), and
accumulated grade point average. Then write the main module which will call
getData to input this information about you and then output it to the
screen. You need only structure definition, main(), and getData().
The output is to be done from main.

The output must be included as a comment below the code for full
credit. AND YOUR NAME MUST BE IN THE CODE AS A COMMENT.
*/

typedef struct student
{
    int pin;
    char *firstName;
    char *lastName;
    int unit;
    float gradePoints;
}STUDENT;

void getData(STUDENT* record);



int main(void)
{
    STUDENT record;
    getData(&record);

    printf("%d\n", record.pin);
    printf("%s\n", record.firstName);
    printf("%s\n", record.lastName);
    printf("%d\n", record.unit);
    printf("%.1f\n", record.gradePoints);
    system("pause");
    return 0;
}
/*==================================================*/
void getData(STUDENT* record)
{
    char input_string[200];

    printf("Enter pin: ");
    scanf("%d", &(*record).pin);

    printf("Enter firstname: ");
    scanf("%s", input_string);
    (*record).firstName = (char*)calloc(strlen(input_string)+1, sizeof(char));
    strcpy((*record).firstName, input_string);

    printf("Enter lastname: ");
    scanf("%s", input_string);
    (*record).lastName = (char*)calloc(strlen(input_string)+1, sizeof(char));
    strcpy((*record).lastName, input_string);

    printf("Enter Units taken ");
    scanf("%d", &(*record).unit);

    printf("Enter average grade points ");
    scanf("%f", &(*record).gradePoints);

    return;
}
/*
My Test Session :
*/
