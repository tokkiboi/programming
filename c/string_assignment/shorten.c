#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void deleteLastCharacter(char* arr);
/*
Write a function that accepts a string (a pointer to a character) and
deletes the last character by moving the null character one position to the left.

Also write a main function that inputs your family name, calls this function,
and then ourputs your family name after the call (it should be missing the last 
letter at this point).Copy your code and the output (as a comment at the bottom
of the code) as run by entering your name
*/

int main(void)
{
    char* b;
    int n;
    char* constant_string = "Mukherjee";
    char* variable_string;
    variable_string = (char*)calloc(strlen(constant_string)+1, sizeof(char));
    strncpy(variable_string, constant_string, strlen(constant_string));
    deleteLastCharacter(variable_string);
    printf("%s\n", variable_string);
    system("pause");
    return 0;
}


/*=========deleteLastCharacter=============*/
void deleteLastCharacter(char* arr)
{
    int n;
    n = strlen(arr);
    *(arr+n-1) = 0;
    return ;
}
  
