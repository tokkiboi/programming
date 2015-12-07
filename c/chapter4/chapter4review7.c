#include <stdio.h>

int calcJanFirst(int year);

int main(void)
{
    int year = 2008;
    int jan_first;

    jan_first = calcJanFirst(year);

    printf("January first, %d: %d\n", year, jan_first);
    return 0;
}
/*0 = Sunday;
1 = Monday;
2 = Tuesday;
3 = Wednesday;
4 = Thursday;
5 = Friday;
6 = Saturday;*/
 int calcJanFirst(int year)
 {
    year = year-1;
    return (year * 365 + year/4 - year/100 + year/400 + 1) % 7;

 }
/*
my output:
January first, 2008: 2

Process returned 0 (0x0)   execution time : 0.010 s
Press any key to continue.

*/
