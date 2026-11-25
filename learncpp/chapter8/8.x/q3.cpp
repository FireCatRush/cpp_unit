/*
Implement a game of Hi-Lo. First, your program should pick a random integer between 1 and 100. 
The user is given 7 tries to guess the number.

If the user does not guess the correct number, the program should tell them whether 
they guessed too high or too low. If the user guesses the right number, the program should tell them they won. 
If they run out of guesses, the program should tell them they lost, and what the correct number is. 
At the end of the game, the user should be asked if they want to play again. 
If the user doesn’t enter ‘y’ or ‘n’, ask them again.

For this quiz, assume the user enters a valid number.

Use the Random.h header from 8.15 -- Global random numbers (Random.h).

Here’s what your output should look like:

Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Correct! You win!
Would you like to play again (y/n)? y
Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Your guess is too high.
Guess #5: 36
Your guess is too low.
Guess #6: 45
Your guess is too low.
Guess #7: 48
Your guess is too low.
Sorry, you lose. The correct number was 49.
Would you like to play again (y/n)? q
Would you like to play again (y/n)? n
Thank you for playing.
For extra credit: make the minimum and maximum values and the number of guesses a configurable parameter.
*/

#include "Random.h"
#include <iostream>
#include <string>

void HiLo(){
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    int expr {Random::get(1, 100)};
    int round {0};
    int user_input {};
    
    while (true){
        ++round;
        std::cout << "Guess #" << round;
        std::cin >> user_input;
        std::cout << "\n";
        if (user_input > expr){
            std::cout << "Your guess is too high.\n";
        }
        else if (user_input < expr)
        {
            std::cout << "Your guess is too low.\n";
        }
        else{
            std::cout << "Correct! You win!\n";
            break;
        }
        if (round == 7){
            std::cout << "Sorry, you lose. The correct number was" << expr << ".\n";
            break;
        }
    }
}

bool IsRerun(){
    std::string key {};
    while (true)
    {
        std::cout << "Would you like to play again (y/n)?";
        std::cin >> key;
        if (key == "y"){
            return true;
        }
        else if (key == "n")
        {
            return false;
        }
        else{
            continue;
        }
        
    }
}


int main(){
    bool isrerun {false};
    while (true)
    {
        HiLo();
        isrerun = IsRerun();
        if (!isrerun){
            break;
        }

    }
    
    std::cout << "Thank you for playing.";
    return 0;
}