#include<stdio.h>

int main()
{
    int num[10], i, maxI;

    for(i=0; i<10; i++)
        scanf("%d", &num[i]);

     for(i=0; i<9; i++)
     {
         for(int j=i+1; j<10; j++)
         {
             if(num[i] == num[j])
             {
                 printf("duplicate %d %d", i, j);
             }
         }
     }

        return 0;
}
