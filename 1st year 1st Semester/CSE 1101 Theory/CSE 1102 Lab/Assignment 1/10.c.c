#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cy, by, age;

    printf("Enter Current year:");
    scanf("%d", &cy);

    printf("\nEnter Birth year:");
    scanf("%d", &by);

    age = cy - by;

    printf("\n\nAge:%d\n", age);






    return 0;
}
