#include <stdio.h>
#include <stdlib.h>

int main()
{
    float inches, yards, feet;

    printf("Enter a measurement in inches:");
    scanf("%f", &inches);

    yards= inches/36;
    feet = inches/12;

    printf("\n\nThe number in yards: %f", yards);
    printf("\nThe number in feet: %f", feet);


    return 0;
}
