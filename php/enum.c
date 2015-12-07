#include<stdio.h>
#include<stdlib.h>
typedef enum {
    RED=3,
    BLUE,
    GREEN=3,
    PINK,
}ENUM;

int main(void)
{
    ENUM color;
    color = 5;
    color = BLUE;
    printf("%d %d %d %d\n", RED, BLUE, GREEN, PINK);
    return 0;
}
