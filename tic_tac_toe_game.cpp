/**
 * @file tic_tac_toe_game.cpp
 * @brief This program implements a simple Tic Tac Toe game for two players.
 *
 * @author Krishna Chauhan
 * @date 2024-10-29
 * 
 * @details
 * The game is played on a 3x3 board where two players take turns to mark the cells
 * with 'X' and 'O'. The player who succeeds in placing three of their marks in a 
 * horizontal, vertical, or diagonal row wins the game. If all cells are filled 
 * without any player achieving this, the game is declared a draw.
 * 
 * The program includes the following functions:
 * - bord(): Displays the current state of the game board.
 * - player_turn(): Handles the player's turn, allowing them to mark a cell.
 * - gameover(): Checks the game state to determine if there is a winner or if the game is a draw.
 * - main(): The main function that runs the game loop until the game is over.
 * 
 * @note
 * The game uses a global 3x3 character array to represent the board and keeps track of 
 * the current player's turn and whether the game has ended in a draw.
 */

#include <iostream>
using namespace std;
char brd[3][3] = {
    {
        '1',
        '2',
        '3',
    },
    {
        '4',
        '5',
        '6',
    },
    {
        '7',
        '8',
        '9',
    },
};
char turn = 'O';
int row, column;
bool draw = false;
void bord()
{
    system("cls");
    cout << "\n\n\t       T I C   T A C    T O E " << endl;
    cout << "\n\tPlayer 1 [X]";
    cout << "\n\tPlayer 2 [0]";
    cout << "\t\t\n";
    cout << endl;
    cout << "\t\t  " << brd[0][0] << "   |  " << brd[0][1] << "  |  " << brd[0][2] << "  \n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t _____|_____|_____\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t  " << brd[1][0] << "   |  " << brd[1][1] << "  |  " << brd[1][2] << "  \n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t _____|_____|_____\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t  " << brd[2][0] << "   |  " << brd[2][1] << "  |  " << brd[2][2] << "  \n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t      |     |     \n";
}
void player_turn()
{
    int choice;
    if (turn == 'X')
        cout << "\t\nEnter your location to mark[1-9] Player 1 turn [X]:";
    if (turn == 'O')
        cout << "\t\nEnter your location to mark[1-9]  Player 2 turn [O]:";
    cin >> choice;
    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "invalid Choice:";
        break;
    }
    if (turn == 'X' && brd[row][column] != 'X' && brd[row][column] != 'O')
    {
        brd[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && brd[row][column] != 'X' && brd[row][column] != 'O')
    {
        brd[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box already filled! Try again!!\n\n";
        player_turn();
    }
    bord();
}
bool gameover()
{
    for (int i = 0; i < 3; i++)
        if (brd[i][0] == brd[i][1] && brd[i][0] == brd[i][2] || brd[0][i] == brd[1][i] && brd[0][i] == brd[2][i])
            return false;

    if (brd[0][0] == brd[1][1] && brd[0][0] == brd[2][2] || brd[0][2] == brd[1][1] && brd[0][0] == brd[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (brd[i][j] != 'X' && brd[i][j] != 'O')
                return true;

    draw = true;
    return false;
}
int main()
{
    while (gameover())
    {
        bord();
        player_turn();
        gameover();
    }

    if (turn = 'X' && draw == false)
        cout << "Player 2 [O] Wins!! Congratulations.\n";
    else if (turn = 'O' && draw == false)
        cout << "Player 1 [X] Wins!! Congratulations.\n";
    else
        cout << "Game is Draw!!\n";
}