#include <stdio.h>
#include <stdlib.h>

int main()
{
    float maths, phy, chem, Bangla, English, total, per;

    printf("Enter the mark obtained in Maths:");
    scanf("%f", &maths);

    printf("Enter the mark obtained in Physics:");
    scanf("%f", &phy);

    printf("Enter the mark obtained in Chemistry:");
    scanf("%f", &chem);

    printf("Enter the mark obtained in Bangla:");
    scanf("%f", &Bangla);

    printf("Enter the mark obtained in English:");
    scanf("%f", &English);

    total= maths+phy+chem+Bangla+English;
    per= total/5.0;

    printf("\n\nAggregate marks: %f", total);
    printf("\nPercentage of obtained marks: %f %%\n", per);




    return 0;
}
