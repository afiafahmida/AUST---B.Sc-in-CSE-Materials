#include<stdio.h>

int main()
{
    int num[10], i, maxI;

    for(i=0; i<10; i++)
        scanf("%d", &num[i]);
    maxI = 0;
    for(i=1; i<10; i++)
    {
        if(num[maxI]<num[i])
        {
            maxI = i;
        }
    }
    printf("%d", num[maxI]);
    return 0;
}
