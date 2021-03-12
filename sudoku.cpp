#include<iostream>
#include<limits>
#define N 9

class Sudoku
{
public:
    bool enterDigits(int arr[][N]);
    bool solve(int arr[][N]);
    void print(int arr[][N]);
};

bool Sudoku::enterDigits(int arr[][N])
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
                return false;
            }
            arr[i][j] = temp;
        }
    }
    std::cout << "\n";
    return true;
}
bool validateBoard(int arr[][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[i][j] > 9 || arr[i][j] < 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::print(int arr[][N])
{
    std::cout << " ** * * * * * * * * * * * * * * * * * * \n";
    std::cout << " * The solution of entered SUDOKU is: *\n";
    std::cout << " ** * * * * * * * * * * * * * * * * * *\n";
    std::cout<< "\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool findEmptyCell(int arr[][N], int& r, int& c)    // r || R is row; c || C is column
{
    for (r = 0; r < N; r++)
    {
        for (c = 0; c < N; c++)
        {
            if (arr[r][c] == 0)
            {
                 return true;
            }
        }
    }
    return false;
}
bool isROk(int arr[][N], int r, int i)
{
    for (int c = 0; c < N; c++)
    {
        if (arr[r][c] == i)
        {
            return true;
        }
    }
    return false;
}

bool isCOk(int arr[][N], int c, int i)
{
    for (int r = 0; r < N; r++)
    {
        if (arr[r][c] == i)
        {
            return true;
        }
    }
    return false;
}
bool isBoxOk(int arr[][N], int boxR, int boxC, int i)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (arr[r + boxR][c + boxC] == i)
            {
                return true;
            }
        }
    }
    return false;
}

bool isAllOk(int arr[][N], int r, int c, int i)
{
    return !isROk(arr, r, i) && !isCOk(arr, c, i) &&
        !isBoxOk(arr, r - r % 3, c - c % 3, i);
}

bool Sudoku::solve(int arr[][N])
{
    int r = 0, c = 0;
    if (!findEmptyCell(arr, r, c))
    {
        return true;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (isAllOk(arr, r, c, i))
        {
            arr[r][c] = i;
            if (solve(arr))
            {
                return true;
            }
            arr[r][c] = 0;
        }
    }
    return false;
}

int main()
{
  char ch = 'y';
  while (ch != 'n')
  {
      int board[N][N] = {}; /* { 
                                {3, 0, 6, 5, 0, 8, 4, 0, 0},
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                {0, 0, 5, 2, 0, 6, 3, 0, 0} 
                               }; 
                        
                        
           int board[N][N] =   {
                                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                {0, 0, 0, 0, 8, 0, 0, 7, 9} 
                               };   */
                        
                         
      Sudoku sudObj;
      if (sudObj.enterDigits(board))
      {
          if (!validateBoard(board))
          {
              std::cout << " Wrong input \n";
              continue;
          }
          if (sudObj.solve(board))
          {
              sudObj.print(board);
          }
          else
          {
              std::cout << "Sudoku have not solution\n" << "\n";
              continue;
          }
      }
      std::cout << "\n Do you want to solve other SUDOKU? y/n \n";
      std::cin >> ch;
  }
  return 0;
}
