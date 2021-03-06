#include<iostream>
#include "Sudoku.h"

int main()
{
  try
  {
    char ch = 'y';
    while (ch != 'n')
    {
      /*
      for test_1
      3 0 6 5 0 8 4 0 0
      5 2 0 0 0 0 0 0 0
      0 8 7 0 0 0 0 3 1
      0 0 3 0 1 0 0 8 0
      9 0 0 8 6 3 0 0 5
      0 5 0 0 9 0 6 0 0
      1 3 0 0 0 0 2 5 0
      0 0 0 0 0 0 0 7 4
      0 0 5 2 0 6 3 0 0
       
      hard Sudoku test_2
      0 0 0 0 0 0 0 0 2
      0 0 9 0 0 7 8 0 0
      0 0 0 0 0 3 0 4 0
      0 0 0 0 0 0 0 5 0
      2 0 8 0 4 0 0 9 0
      7 0 3 1 0 0 2 0 0
      1 0 0 0 0 9 7 0 3
      0 7 0 5 6 0 9 0 0
      0 6 0 3 0 0 0 0 5
      */
      Sudoku sudObj;
      sudObj.enterDigits();
      
      if (sudObj.solve(0,0))
      {
        sudObj.print();
      }
      else
      {
        std::cout << "Sudoku have not solution\n" << "\n";
        continue;
      }
      std::cout << "\n Do you want to solve other SUDOKU? y/n \n";
      std::cin >> ch;
    }
  }
  catch(const std::runtime_error& ex)
  {
      std::cout<< ex.what();
  }
  return 0;
}
