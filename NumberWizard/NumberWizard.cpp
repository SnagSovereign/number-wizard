#include <iostream>
#include <windows.h>

using namespace std;

//Declare variables
int minGuess;
int maxGuess;
int guessCount;
int calculatedGuess;
bool correctGuess;

void Reset()
{
    //reset all variables to default value
    minGuess = 0;
    maxGuess = 1000 + 1; //+1 allows the user to choose 0 or 1000 as their number
    guessCount = 0;
    correctGuess = false;
}

void GreetUser()
{
    //clear the screen
    system("CLS");

    //Greet the user and ask them to pick a number between 0 and 1000
    std::cout << "Greetings! This is Number Wizard! Think of a number between " << minGuess << " and " << maxGuess - 1 << ".";
    std::cout << "\nPlease don't tell me, I want to try and guess it!\n";
}

int CalculateGuess()
{
    //use the mean of the minGuess and maxGuess as the calculate guess
    calculatedGuess = (minGuess + maxGuess) / 2;
    return calculatedGuess;
}

void Guess()
{
    //Ask the user if their number is higher or lower than the calculated guess
    std::cout << "\nIs your number 'higher', 'lower' or 'equal' to " << CalculateGuess() << "? ";
    //increment the guessCount
    guessCount++;
}

void PlayGame()
{
    //Reset all variables
    Reset();

    //Greet the user
    GreetUser();

    //While the computer has not yet calculated the correct guess, continue to guess
    while (correctGuess == false)
    {
        //Ask the user if their number is higher or lower than the calculated guess
        Guess();

        //Accept key input from the user and store it
        string userInput;
        cin >> userInput;

        //if the user claims their number is HIGHER than the guess
        if (userInput == "higher")
        {
            //Make the min guess = the current guess
            minGuess = calculatedGuess;
        }
        //if the user claims their number is LOWER than the guess
        else if (userInput == "lower")
        {
            //Make the max guess = the current guess
            maxGuess = calculatedGuess;
        }
        //if the user claims their number is EQUAL to the guess
        else if (userInput == "equal")
        {
            correctGuess = true;
            //tell the user that the computer won
            std::cout << "\nWoo hoo! I win! Your number was " << calculatedGuess << " and it took me " << guessCount << " guesses!\n";
            //ask the user if they would like to play again
            std::cout << "Would you like to play again? (y/n) ";
            //save user input
            cin >> userInput;
            //if the user wants to play again
            if (userInput == "y")
            {
                //replay the game
                PlayGame();
            }
        }
    }
}

//Start
int main()
{
    //change the console title
    SetConsoleTitle(TEXT("Number Wizard"));

    //run the game
    PlayGame();
}