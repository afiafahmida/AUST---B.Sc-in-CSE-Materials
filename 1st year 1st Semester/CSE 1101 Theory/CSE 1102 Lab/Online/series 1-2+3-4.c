#include<stdio.h>

int main()
{
    int N, sum1, sum2, sum;
    scanf("%d", &N);

    printf("1");
    for (int i=2; i<=N; i++)
    {
        if(i%2==0)
            printf("-%d", i);
        else
            printf("+%d", i);
    }

    return 0;
}
