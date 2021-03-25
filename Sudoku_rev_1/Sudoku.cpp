#include<iostream>
#include "Sudoku.h"

void Sudoku::enterDigits()
{
    std::cout << " ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n";
    std::cout << " * Please enter Sudoku 9 X 9 which you whant to solve, enter 0 for empty cells: *\n";
    std::cout << " ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    int temp = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            while (!(std::cin >> temp))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Wrong input!";
                return ;
            }
            board[i][j] = temp;
        }
    }
    std::cout << "\n";
}

bool Sudoku::validateBoard()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] > 9 || board[i][j] < 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::print()
{
    std::cout << " ** * * * * * * * * * * * * * * * * * * \n";
    std::cout << " * The solution of entered SUDOKU is: *\n";
    std::cout << " ** * * * * * * * * * * * * * * * * * *\n";
    std::cout<< "\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Sudoku::findEmptyCell(int arr[][N], int& r, int& c)    // r || R is row; c || C is column
{
    for (r = 0; r < N; r++)
    {
        for (c = 0; c < N; c++)
        {
            if (board[r][c] == 0)
            {
                 return true;
            }
        }
    }
    return false;
}
bool Sudoku::isROk(int arr[][N], int r, int i)
{
    for (int c = 0; c < N; c++)
    {
        if (board[r][c] == i)
        {
            return true;
        }
    }
    return false;
}
bool Sudoku::isCOk(int arr[][N], int c, int i)
{
    for (int r = 0; r < N; r++)
    {
        if (board[r][c] == i)
        {
            return true;
        }
    }
    return false;
}
bool Sudoku::isBoxOk(int arr[][N], int boxR, int boxC, int i)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (board[r + boxR][c + boxC] == i)
            {
                return true;
            }
        }
    }
    return false;
}

bool Sudoku::isAllOk(int arr[][N], int r, int c, int i)
{
    return !isROk(arr, r, i) && !isCOk(arr, c, i) &&
        !isBoxOk(arr, r - r % 3, c - c % 3, i);
}

bool Sudoku::solve(int r, int c)
{
    if (!findEmptyCell(board, r, c))
    {
        return true;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (isAllOk(board, r, c, i))
        {
            board[r][c] = i;
            if (solve(r,c))
            {
                return true;
            }
            board[r][c] = 0;
        }
    }
    return false;
}