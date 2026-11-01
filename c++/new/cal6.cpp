#include <stdio.h>

int main()
{
    float m1,m2,m3,average;

    printf("Enter marks of three subjects 1: ");
    scanf("%f",&m1);

    printf("Enter marks of three subjects 2: ");
    scanf("%f",&m2);

    printf("Enter marks of three subjects 3: ");
    scanf("%f",&m3);\

    average = (m1+m2+m3)/3;

    printf("average = %.2f",average);

    return 0;
        
}