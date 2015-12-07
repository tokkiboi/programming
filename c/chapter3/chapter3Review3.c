#include <stdio.h>
int main(void)
{
int a;
int b;
int c;
int d;

a = 10;
b += 5;
    printf("%3d\n", a);

a = b = c = 10;
d = a+ b++ + ++c;

    printf("%3d %3d %3d %3d\n", a, b, c, d);
    return 0;
}
