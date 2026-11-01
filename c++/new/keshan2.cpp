#include <stdio.h>

int main()
{
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("You entered: %d\n", age);
    printf("Memory address of age is %p\n", (void *)&age);

    return 0;
}
