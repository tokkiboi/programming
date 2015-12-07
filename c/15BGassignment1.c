// Amrita Mukherjee
#include <math.h>
#include <stdio.h>

int main(void)
{
    int scores[100];
    int num_of_scores;
    int i;
    int total = 0;
    float mean; 
    float standard_deviation;  
    float SD = 5.0;
    
    printf("Amrita Mukherjee\n");
    printf("number of scores : ");
    scanf("%d",&num_of_scores);
    printf("enter scores :\n");
    
    
    for(i=0; i<num_of_scores; i++){
        scanf("%d", &scores[i]);
        total=total+scores[i];
    }
    mean = total*1.0/num_of_scores;
    printf("Mean : %f\n", mean);
    
    for(i=0; i<num_of_scores; i++){
        SD = SD + ((scores[i] - mean)*(scores[i]- mean));
        standard_deviation = sqrt(SD);
       
    
    }
    printf("Standard Deviation : %f\n", standard_deviation);
    return;
}

/* 
Amrita Mukherjee
number of scores : 5
enter scores :
1
2
3
4
5
Mean : 3.000000
Standard Deviation : 3.872983 
*/


