#include <stdio.h>

int main (void)
{
    int n;
    int isprime;
    int divider;
    int remainder;

    for(n=1;n<=1000000;n=n+1){
        if((n==1) || (n==2) || (n==3)){
            printf("%d\n",n);
        }
        else {
            isprime = 1;
            for(divider = 2; divider <= n/2; divider = divider+1){
                remainder = n % divider;
                if(remainder == 0){
                    isprime = 0;
                    break;
                }
            }
            if (isprime == 1){
                printf("%d\n", n);
            }
        }
    }
 }
 
