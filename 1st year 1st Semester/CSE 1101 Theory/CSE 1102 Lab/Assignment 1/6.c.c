#include <stdio.h>
#include <stdlib.h>

int main()
{
    float maths, phy, chem, Bangla, English, total, avg;

    printf("\nEnter Name: Afia");
    printf("\nEnter Roll: 032");

    printf("\n\nEnter the mark obtained in Maths:");
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
    avg = total/5.0;

    printf("\n\nTotal obtained marks: %f", total);
    printf("\nAverage obtained marks: %f\n", avg);



    return 0;
}
