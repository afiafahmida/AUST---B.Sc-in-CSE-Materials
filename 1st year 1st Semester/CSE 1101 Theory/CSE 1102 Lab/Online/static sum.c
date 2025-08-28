#include<stdio.h>

int fun1();
int fun2(int n);
void main()
{
    printf("%d\n", fun1());
    printf("%d\n", fun1());
    printf("%d\n", fun1());
}

int fun1(int n)
{

    static int x=0;
    x++;

    return x;
}
