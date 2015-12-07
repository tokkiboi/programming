#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char line[] = "abcdefghijkl"; 
	char (*a)[2];
	char (*b)[4];
	a = (char(*)[2])line;
	b = (char(*)[4])line;

	printf("%s\n%s\n%s\n\n\n", a+0, a+1, a+2);
	printf("%s\n%s\n%s\n\n\n", b+0, b+1, b+2);
	printf("%c\n\n\n", b[2][2]);

	system("pause");
	return 0;

}