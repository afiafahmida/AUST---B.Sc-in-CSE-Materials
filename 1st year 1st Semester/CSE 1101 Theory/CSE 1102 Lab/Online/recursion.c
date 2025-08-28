#include<stdio.h>

int sum(int num)

int main()
{
    int num, sum;
    scanf("%d", &num);
    printf("%d", sum(num));
    return 0;
}

int sum (int n)
{
    if(n==0)
        return 0;
    else
    return (n%10)+sum(n/10);
}
