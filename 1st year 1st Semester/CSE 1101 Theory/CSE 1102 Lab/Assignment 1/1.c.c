#include <stdio.h>
#include <stdlib.h>

int main()
{
    float km, m, feet, inches, cm;

    printf("Enter the distance between Dhaka and Rajshahi:");
    scanf("%f", &km);

    m = km* 1000;
    cm = km * 100000;
    feet= km* 3280;
    inches=km* 39370;


    printf("The distance between Dhaka and Rajshahi is\n %fmeters\n %ffeet\n %finches\n and %fcm\n", m, feet, inches, cm);




    return 0;
}
