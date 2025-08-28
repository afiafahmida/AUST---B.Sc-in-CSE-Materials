#include<stdio.h>

int main()

{
    int N, M, i, GCD, LCM;
    scanf("%d%d", &N, &M);

    for(i=1; N>=i && M>=i; i++)
    {
        if(N%i==0 && M%i==0)
            GCD=i;
    }
    LCM = (N*M)/GCD;
    printf("The LCM of the numbers are %d\n", LCM);
    printf("The GCD of the numbers are %d\n", GCD);

    return 0;
}
