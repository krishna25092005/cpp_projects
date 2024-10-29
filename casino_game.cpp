/**
 * @file casino_game.cpp
 * @brief A simple casino game where players can bet money on guessing a number between 1 and 10.
 *
 * This application provides a command-line interface for a casino game. Players can enter their name, deposit an amount, and place bets on guessing a number between 1 and 10. If the guessed number matches the randomly generated number, the player wins 10 times the betting amount; otherwise, they lose the betting amount.
 *
 * @author Krishna Chauhan
 * @date 2024-10-29
 *
 * @details
 * The application uses standard input/output for interaction with the player. It also uses random number generation to simulate the casino game. The main functionalities include:
 * - Displaying game rules
 * - Allowing players to place bets
 * - Generating a random number for the game
 * - Calculating and updating the player's balance based on the game outcome
 *
 * The game continues until the player decides to quit or runs out of money.
 *
 * @note
 * This is a simple implementation and does not include advanced features like graphical user interface or networked multiplayer support.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
    {
        cout << symbol;
    }
    cout << endl;
}

void rules()
{
    cout << "\n\n";
    drawLine(60, '-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(60, '-');
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n";
    drawLine(60, '-');
    cout << "\n\n";
}

int main()
{
    string playerName;
    int amount;
    int bettingAmount;
    int guess;
    int dice;
    char choice;

    srand(time(0));

    drawLine(60, '_');
    cout << "\n\n\n\t\t C A S I N O  G A M E \n\n\n\n";
    drawLine(60, '_');

    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);

    cout << "\n\nEnter Deposit Amount to Play Game : $";
    cin >> amount;

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $" << amount << "\n";

        // Get Player's betting amount
        do
        {
            cout << playerName << ", Enter Money to bet : $";
            cin >> bettingAmount;
            if (bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                     << "\nRe-enter amount\n";
        } while (bettingAmount > amount);

        // Get Player's Numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 : ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                     << "Re-enter number\n";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // Will hold the randomly generated integer between 1 and 10.

        if (dice == guess)
        {
            cout << "\n\nGood Luck ! You won $" << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }

        else
        {
            cout << "\n\nBad Luck ! You lost $" << bettingAmount;
            amount = amount - bettingAmount;
        }

        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n"
             << playerName << ", You have $" << amount << "\n";

        if (amount == 0)
        {
            cout << "\nYou have no money to play.";
            break;
        }

        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing the game. Your balance amount is $"
         << amount << ".\n\n";
    drawLine(70, '=');

    return 0;
}