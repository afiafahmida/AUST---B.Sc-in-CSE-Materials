#include <stdio.h>
#include <stdlib.h>

int main()
{
    float F, C;
    printf("Enter the Temperature in Fahrenheit:");
    scanf("%f", &F);

    C = ((F-32)/9)*5;

    printf("The dropped temperature in Centigrade is %f\n", C);




    return 0;
}
