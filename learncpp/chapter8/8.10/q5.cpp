/*
    Modify the FizzBuzz program you wrote in the previous quiz to add the rule that 
    numbers divisible by seven should be replaced with “pop”. Run the program for 150 iterations.

    In this version, using an if/else chain to explicitly cover every possible 
    combination of words will result in a function that is too long. 
    Optimize your function so only 4 if-statements are used: 
    one for each of the non-compound words (“fizz”, “buzz”, “pop”), 
    and one for the case where a number is printed.
*/

/*
    Modify the FizzBuzz program you wrote in the previous quiz to add the rule that 
    numbers divisible by seven should be replaced with “pop”. Run the program for 150 iterations.

    In this version, using an if/else chain to explicitly cover every possible 
    combination of words will result in a function that is too long. 
    Optimize your function so only 4 if-statements are used: 
    one for each of the non-compound words (“fizz”, “buzz”, “pop”), 
    and one for the case where a number is printed.
*/

#include <iostream>
#include <string>

void fizzbuzz(int num);

int main()
{
    int num{150};
    fizzbuzz(num);
    return 0;
}

void fizzbuzz(int num)
{
    for (int i{1}; i <= num; ++i)
    {
        std::string out{};

        if (i % 3 == 0)
            out += "fizz";
        if (i % 5 == 0)
            out += "buzz";
        if (i % 7 == 0)
            out += "pop";
        if (out.empty())
            out = std::to_string(i);

        std::cout << out << '\n';
    }
}