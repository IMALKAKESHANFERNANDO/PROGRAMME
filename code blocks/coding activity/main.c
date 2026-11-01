#include <iostream>

int main()
{
    double a, b;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> b;

    if (op == '+')
        std::cout << "Answer = " << a + b;
    else if (op == '-')
        std::cout << "Answer = " << a - b;
    else if (op == '*')
        std::cout << "Answer = " << a * b;
    else if (op == '/')
        std::cout << "Answer = " << a / b;
    else
        std::cout << "Invalid operator";

    return 0;
}
