#include<stdio.h>

int main ()
{
    long long int n;
    scanf("%lld",&n);
    if(n%2==0){
        if((n/2)%2==0){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    else{
        if(((n-1)/2)%2==1){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}
