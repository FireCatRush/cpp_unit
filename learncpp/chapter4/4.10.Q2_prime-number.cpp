/*
    A prime number is a whole number greater than 1 
    that can only be divided evenly by 1 and itself. 
    Write a program that asks the user to enter a number 0 through 9 (inclusive). 
    If the user enters a number within this range that is prime (2, 3, 5, or 7), 
    print “The digit is prime”. Otherwise, print “The digit is not prime”.
*/

#include <iostream>

int UserInput(){
    int input;
    std::cout << "wait for input a number and to calculate prime number...\n";
    std::cout << "Input here: \n";
    std::cin >> input;
    while (true)
    {   
        if (input > 9 || input < 1){
            std::cout << "Number should be in 1-9\n";
        }
        else
            break;
    }
    
    std::cout << "user input `" << input << "`:";
    std::cout << "\n";
    return input;
}


int main(){
    int choice;
    choice = UserInput();
    if (choice == 2 || choice == 3 || choice == 5 || choice == 7){
        std::cout << "The digit is prime";
    }
    else{
        std::cout << "The digit is not prime";
    }

    return 0;
}