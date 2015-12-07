#include <stdio.h>
int main(void)
{
    int a;
    int b;
    int c;
    int d;

    printf("%d\n", (12-10/(6-3-1))*(9%6-9/6));

    a=10;
    b=5;
    a += b+3;
    printf("%d %d\n", a,b);

    a=10;
    b=5;
    a -= b+3;
    printf("%d %d\n", a,b);

    a=10;
    b=5;
    a *= b+3;
    printf("%d %d\n", a,b);

    a = 50;
    b = ++a + 3;

    a = 50;
    c = a++ +3;

    d = ++a + a++;
    printf("%d %d %d %d\n", a, b, c, d);

    a = 14;
    b = 4;
    d = a - b *2;
    c = b++ * 100 - --a % d++;
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}
