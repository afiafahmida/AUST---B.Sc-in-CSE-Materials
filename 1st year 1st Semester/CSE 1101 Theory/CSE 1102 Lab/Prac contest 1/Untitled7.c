#include<stdio.h>

int main()
{
    int k, n,w, i, z=0, a;

    scanf("%d%d%d", &k, &n, &w);

    for (i=1; i<=w; i++)
        z = z+(i*k);

    if(z>=n)
    {a= z-n;
        printf("%d\n", a);}

    else
        printf("0\n");


    return 0;
}
