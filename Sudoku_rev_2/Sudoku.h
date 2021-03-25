class Sudoku
{
  public:
    void enterDigits();
    bool solve(int r, int c); // r || R is row; c || C is column
    void print();
    bool validateBoard();
    
  private:
    static const int  N = 9;
    int board[N][N];
    bool findEmptyCell(int& r, int& c);
    bool isROk(int r, int i);
    bool isCOk(int c, int i);
    bool isBoxOk(int boxR, int boxC, int i);
    bool isAllOk(int r, int c, int i);
};