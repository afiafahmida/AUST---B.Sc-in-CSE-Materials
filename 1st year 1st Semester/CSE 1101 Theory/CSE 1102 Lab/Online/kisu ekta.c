#include<stdio.h>

void main()
{
    int r, c;
scanf("%d %d",&r ,&c);

int i, j;
int cnt=r * c;
for (i=1; i<=cnt; i++)
 {
     printf("%d", i);
     if(i%4==0)
    printf("\n");}
}
