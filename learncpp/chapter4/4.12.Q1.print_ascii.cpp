/*
    Write a short program where the user is asked to enter a single character. 
    Print the value of the character and its ASCII code, using static_cast.
*/

#include <cstdint>
#include <iostream>

int main()
{
    std::cout << "Enter a number character: ";
    char ch{};
    std::cin >> ch;

    std::cout << "You entered: " << ch << '\n';
    std::cout << "Its ASCII = " << static_cast<int>(ch) << '\n';
    return 0;
}