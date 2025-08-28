#include<stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for(int j=1; j<=T; j++)
    {
        long long int a, b, i, sum=0;

        scanf("%lld", &a);
        scanf("%lld", &b);

        for (i=0; a<=i && b>=i; i++)
        {
            if (i%2!=0)
                sum+=i;
                break;
        }
          printf("%lld", sum);

    }

    return 0;
}
