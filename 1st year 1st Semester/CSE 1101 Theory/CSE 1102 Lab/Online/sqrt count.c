#include<stdio.h>

int main()
    {
        long long int a, b, cnt=0;

        scanf("%lld %lld", &a, &b);

        for (int i=a; b<=i; i++)
        {
            {if(i*i== sqrt(i))
                cnt++;
        }
        printf("%lld", cnt);


        return 0;
    }
