#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, quotient, remainder;

    printf("Enter the dividend:");
    scanf("%d", &x);

    printf("Enter the divisor:");
    scanf("%d", &y);

    quotient= x/y;
    remainder=x%y;

    printf("\nQuotient:%d", quotient);
    printf("\nRemainder:%d", remainder);

    return 0;
}
