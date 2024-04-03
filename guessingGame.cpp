//This is a simple program of the Number Guessing Game
//One can take many attempts to guess the correct number 

//Include the header files
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    
    srand(time(0));  //seed the random number generator
    int randomNumber, guess, attempts;

    do {
        attempts = 0;
        randomNumber = rand() % 100 + 1;

        std::cout << "\nGuess the number (between 1 and 100): ";

        do {

            //Check for valid input
            if (!(std::cin >> guess)) {
                std::cout << "Invalid input. Please enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            attempts++;  //keeping track of the number of attempts

            //feedback about the guessed number
            if (guess > randomNumber) std::cout << "Too high! Try with a smaller number: ";
            else if (guess < randomNumber) std::cout << "Too low! Try with a larger number: ";

        } while (guess != randomNumber);

        //displays the number of attempts taken
        std::cout << "\nCongratulations! You guessed the number in " << attempts << " attempts." << std::endl;

        std::cout << "\nDo you want to play again? (1 for Yes, 0 for No): ";

        if (!(std::cin >> guess)) {
            std::cout << "\nInvalid input! Exiting the game..." << std::endl;
            break;
        }

    } while (guess != 0);

    std::cout << std::endl;

    return 0;
}