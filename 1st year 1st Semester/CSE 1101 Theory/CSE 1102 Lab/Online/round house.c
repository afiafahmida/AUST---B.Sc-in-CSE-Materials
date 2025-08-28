#include<stdio.h>

int main()

{
    int n, a, b, x;
    scanf("%d %d %d", &n, &a, &b);

    x = (a+b+(100*n))%n;
    if(x==0)
        printf("%d", n);
    else
        printf("%d", x);

return 0;
}
