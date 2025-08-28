#include<stdio.h>

void main()
{
    int a, b, z, sum;
    scanf("%d %d", &a, &b);

    for(int i=a; i<=b; i++)
    {
        if(i%2==0 && i%5!=0 && i%3==0)
            {
                sum +=i;
            }
    }
    printf("%d", sum);
}
