#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, square, cube;

    printf("Enter a number: ");
    scanf("%d", &x);

    square = x*x;
    cube = x*x*x;

    printf("\nThe square of input number: %d", square);
    printf("\nThe cube of input number: %d\n", cube);


    return 0;
}
