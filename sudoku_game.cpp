/**
 * @file sudoku_game.cpp
 * @author Krishna Chauhan
 * @date 2024-10-29
 * @brief A program to solve a given Sudoku puzzle using backtracking.
 *
 * This program reads a 9x9 Sudoku puzzle from the user, where empty cells are represented by 0.
 * It then attempts to solve the puzzle using a backtracking algorithm and prints the solved puzzle.
 * If no solution exists, it informs the user.
 *
 * The main functions in this program are:
 * - isSafe: Checks if placing a number in a given cell is valid according to Sudoku rules.
 * - solveSudoku: Solves the Sudoku puzzle using backtracking.
 * - printBoard: Prints the Sudoku board.
 */

#include <iostream>
#include <vector>
using namespace std;

#define N 9

bool isSafe(vector<vector<int>> &board, int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (board[row][x] == num || board[x][col] == num ||
            board[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num)
        {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &board)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            { // Find an empty cell
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(board, row, col, num))
                    {
                        board[row][col] = num;
                        if (solveSudoku(board))
                        {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Enter your Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board))
    {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
