
#include <stdio.h>

int main() {
    int x, y;

    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);

    printf("Sum = %d\n", x + y);
    printf("Difference = %d\n", x - y);
    printf("Product = %d\n", x * y);

    if (y != 0) {
        printf("Quotient = %d\n", x / y);
    } else {
        printf("Quotient is undefined (division by zero).\n");
    }

    return 0;
}
