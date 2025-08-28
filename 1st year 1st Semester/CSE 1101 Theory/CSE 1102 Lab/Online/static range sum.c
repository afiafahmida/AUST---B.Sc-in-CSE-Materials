#include<stdio.h>

int sum(int);
void main()
{
   printf("%d", sum(n));
}

int sum(int n)
{

    if(n==1)
        return 1;
    else
        return n + sum(n-1);
}

 /*false hoye
 return 4 + sum (3)
 cholte thakbe
