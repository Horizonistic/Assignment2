/*
 * Programmer: Jacob Larson
 * Purpose: Simulates a guessing game between the player and a computer.
 * Class: CS222
 * Assignment 2
 *
 * A professor from another class provided us with a "SuperOutput" class which
 * allows you to call one function and output to both the console and the file.
 * I improved it some with new functions and the like, and I think I'm going
 * to port it to C++ because having to duplicate every line just to output it
 * to the file is ridiculous.
 */

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "SuperOutput.h"

using namespace std;

const int maxGuess = 18;
const int maxDiceRoll = 6;
const int numRolls = 3;

int guessComp()
{
    int guess = rand() % (maxGuess - 3) + 3; // Only allows guesses from 3-18
    return guess;
}

int rollDice()
{
    int rolls[numRolls];
    int sum = 0;

    for (int i = 0; i < numRolls; i++)
    {
        rolls[i] = rand() % maxDiceRoll + 1;
        sum += rolls[i];
    }

    return sum;
}

bool score(int user, int comp, int rolls)
{
    int userDiff = 0;
    int compDiff = 0;

    if (user >= rolls)
    {
        userDiff = user - rolls;
    }
    else
    {
        userDiff = rolls - user;
    }

    if (comp >= rolls)
    {
        compDiff = comp - rolls;
    }
    else
    {
        compDiff = rolls - comp;
    }

    return userDiff < compDiff; // True if player is closer, false if computer is closer or distance is even
}


class String
{
public:
    static string toString(int num)
    {
        string temp = "";
        string output = "";
        int quotient, remainder;
        do
        {
            temp = "";
            quotient = num / 10;
            remainder = num % 10;
            num = quotient;
            temp = remainder + 48; // Add 48 to get ASCII character
            // Unable to append to output directly; assigning to temp converts it to string
            output = temp + output;
        }
        while (quotient != 0);

        return output;
    }
};

int main()
{
    SuperOutput * so = new SuperOutput("output.txt");
    so->println(String::toString(1));

    bool outcome = false;

    int userGuess = 0;
    int userScore = 0;

    int compGuess = 0;
    int compScore = 0;

    int rolls = 0;

    bool cheater = false;
    int userWinStreak = 0;

    do
    {
        cout << endl << "The current score is You: " << userScore << "; Computer: " << compScore << endl;
        so->println("The current score is You: " + String::toString(userScore) + "; Computer: " + String::toString(compScore));

        cout << "Please enter a number from 3 to 18, or -1 to exit" << endl;
        so << "Please enter a number from 3 to 18, or -1 to exit" << endl;

        cin >> userGuess;
        so << userGuess << endl;
        if (userGuess <= 18 && userGuess > 2) // If in valid range
        {
            cout << "The computer is now guessing..." << endl;
            so << "The computer is now guessing..." << endl;

            compGuess = guessComp();
            cout << "It has guessed " << compGuess << ".  Now rolling the dice 3 times..." << endl;
            so << "It has guessed " << compGuess << ".  Now rolling the dice 3 times..." << endl;

            rolls = rollDice();
            cout << "Now how's the closest?" << endl;
            so << "Now who's the closest to the number " << rolls << endl;

            outcome = score(userGuess, compGuess, rolls);

            if (outcome) // If player wins
            {
                if (cheater && userWinStreak > 1) // If cheating
                {
                    compScore++;
                    userWinStreak = 0;
                    cout << "Cheater!" << endl;
                    so << "Cheater!" << endl;

                    cout << "This one goes to the computer!" << endl;
                    so << "This one goes to the computer!" << endl;
                }
                else
                {
                    userScore++;
                    userWinStreak++;
                    cout << "It looks like... You won!  You were the closest to the number " << rolls << "." << endl;
                    so << "It looks like... You won!  You were the closest to the number " << rolls << "." << endl;

                    cout << "Let's play again.";
                    so << "Let's play again.";
                }
            }
            else
            {
                compScore++;
                userWinStreak = 0;
                cout << "It looks like... the computer won.  It was closer to the number " << rolls << "." << endl;
                so << "It looks like... the computer won.  It was closer to the number " << rolls << "." << endl;

                cout << "Let's play again." << endl;
                so << "Let's play again." << endl;
            }
        }
        else if (userGuess == -2)
        {
            if (cheater)
            {
                cheater == false;
                cout << "You have disabled cheater mode!  Enter -2 again to enabled it." << endl;
                so << "You have disabled cheater mode!  Enter -2 again to enabled it." << endl;
            }
            else
            {
                cheater = true;
                cout << "You have enabled cheater mode!  Type -2 again to disable it." << endl;
                so << "You have enabled cheater mode!  Type -2 again to disable it." << endl;
            }
        }
        else
        {
            cout << "That number was not in the valid range... :(" << endl;
        }
        so << endl;
    }
    while (userGuess != -1);
     */
    return 0;
}