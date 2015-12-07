#include <stdio.h>

int main (void)
{
    int n;
    int isprime;
    int divider;
    int remainder;
    int primecount=0;
    int primes[1000000];
    int i;

    for(n=1;n<=1000000;n=n+1){
        if(n==1) {
            printf("1: 1\n");
        }
        else if(n==2){
            printf("2: 2\n");
            primes[primecount] = n;
            primecount = primecount+1;
        }
        else {
            isprime = 1;
            for(i = 0; i < primecount; i = i+1){
                divider = primes[i];
                if(divider*2 > n){
                    break;
                }
                remainder = n % divider;
                if(remainder == 0){
                    isprime = 0;
                    break;
                }
            }
            if (isprime == 1){
                printf("%d: %d\n", primecount+2, n);
                primes[primecount]=n;
                primecount=primecount+1;
            }
        }
    }
 }
 
