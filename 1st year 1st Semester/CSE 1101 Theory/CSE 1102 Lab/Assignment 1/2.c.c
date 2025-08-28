#include <stdio.h>
#include <stdlib.h>

int main()
{
    int z, r=0;
    int x;
    printf("Enter a 5 digit number:");
    scanf("%d", &x);

    z=x%10;
    x=x/10;
    r=z;

    z=x%10;
    x=x/10;
    r=r*10+z;

    z=x%10;
    x=x/10;
    r=r*10+z;

    z=x%10;
    x=x/10;
    r=r*10+z;

    z=x%10;
    x=x/10;
    r=r*10+z;

    printf("The reverse of input is %d\n", r);

    return 0;
}
