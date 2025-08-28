#include <stdio.h>


int main()
{
    int A, B, x;

    printf("Enter the value of A:");
    scanf ("%d", &A);

    printf("\nEnter the value of B:");
    scanf("%d", &B);

    x = A;
    A = B;
    B = x;


    printf("\n\nThe value of A: %d", &A);
    printf("\nThe value of B: %d", &B);

    return 0;
}
