#include <stdio.h>
#include <math.h>
int calAreaOfTriangle(int a, int b, int c, int* area);
int main(void)
{
   int a = 10;
   int b = 20;
   int c = 30;

   *area = calAreaOfTriangle(a,b,c,&area);
}

void calAreaOfTriangle(int a, int b, int c, int * area)
{
    int p;
    p = (a+b+c)/2;
    *area = sqrt(p(p-a)(p-b)(p-c));
    printf("Area is: %d\n",*area);
    return;



}
