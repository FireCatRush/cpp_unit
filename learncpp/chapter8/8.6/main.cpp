/*
    Write a function called calculate() that takes two integers 
    and a char representing one of the following mathematical 
    operations: +, -, *, /, or % (remainder). 
    
    Use a switch statement to perform the appropriate mathematical operation on the integers, 
    and return the result. If an invalid operator is passed into the function, 
    the function should print an error message. For the division operator, 
    do an integer division, and don’t worry about divide by zero.
*/

#include <iostream>

int calculate(int a, int b, char sign){
    int result {0};

    switch (sign)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b == 0){
            std::cout << "denominator do not be zero";
            break;
        }
        result = a / b;
        break;
    case '%':
        if (b == 0){
            std::cout << "denominator do not be zero";
            break;
        }
        result = a % b;
        break;
    default:
        std::cout << "error operation";
        break;
    }

    return result;
}

int main(){
    int a{};
    int b{};
    char op{};

    std::cout << "Enter an expression like 1 + 2: ";
    if (!(std::cin >> a >> op >> b))
    {
        std::cout << "bad input\n";
        return 1;
    }
    int res {0};
    res = calculate(a, b, op);

    std::cout << res;
    return 0;
}