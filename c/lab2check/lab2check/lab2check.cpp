#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char s[] = "KNIFE JACK          1.3 6.0 5.1 6.3 5.9 6.5";

	char name[21];
	float level;
	float score1;
	float score2;
	float score3;
	float score4;
	float score5;

	sscanf(s, "%20s %f %f %f %f %f %f", name, &level, &score1, &score2, &score3, &score4, &score5);
	printf("%s %f %f %f %f %f %f ", name, level, score1, score2, score3, score4, score5);
	return 0;
}