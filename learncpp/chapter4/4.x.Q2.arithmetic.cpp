/*
    Write the following program: 
    The user is asked to enter 2 floating point numbers (use doubles). 
    The user is then asked to enter one of the following 
    mathematical symbols: +, -, *, or /. The program computes the answer 
    on the two numbers the user entered and prints the results. 
    If the user enters an invalid symbol, the program should print nothing.

    Example of program:

    Enter a double value: 6.2
    Enter a double value: 5
    Enter +, -, *, or /: *
    6.2 * 5 is 31
*/

#include <iostream>

int main(){
    double a{}, b{};
    char symbol{};
    std::cout << "Enter a double value:";
    std::cin >> a;
    std::cout << "\n";

    std::cout << "Enter a double value:";
    std::cin >> b;
    std::cout << "\n";
    
    std::cout << "Enter +, -, *, or /";
    std::cin >> symbol;
    std::cout << "\n";

    if (symbol == '+')
        std::cout << a << " + " << b << " is " << a + b << '\n';
    else if (symbol == '-')
        std::cout << a << " - " << b << " is " << a - b << '\n';
    else if (symbol == '*')
        std::cout << a << " * " << b << " is " << a * b << '\n';
    else if (symbol == '/')
        std::cout << a << " / " << b << " is " << a / b << '\n';

    return 0;
}