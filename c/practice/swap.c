#include <stdio.h>
#include <math.h>

void swap (int * a, int * b);
int main(void)
{
    int a = 5;
    int b = 7;
    swap(&a, &b);
    printf("after swapping a is %d and b is %d", a, b);

    return 0;
}

void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return;
}
