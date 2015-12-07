#include <stdio.h>
#include <math.h>

int addition(int a, int b);

int main(void)
{
    int a;
    int b;
    int add;
    printf("Please enter two numbers.\n");
    scanf("%d", &a);
    scanf("%d", &b);
    add = addition(a, b);
    printf("%d is sum of these two numbers.", add);
    return 0;
}

int addition(int a, int b)
{
    return a+b;
}
