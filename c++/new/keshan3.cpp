#include <stdio.h>

int main()
{
    float price;

    printf("Enter the price: ");
    scanf("\n %f", &price);

    printf("price: %f\n", price);
    printf("price: %.2f\n", price);
    return 0;
}