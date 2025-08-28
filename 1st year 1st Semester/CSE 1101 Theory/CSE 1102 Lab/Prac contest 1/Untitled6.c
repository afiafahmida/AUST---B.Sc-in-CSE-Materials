#include<stdio.h>
#include<math.h>

int main()
{
    int A, B;
    long double D;

    scanf("%d %d", &A, &B);

    D = (100-((100.00*B)/A));

    printf("%Lf\n", D);

    return 0;
}
