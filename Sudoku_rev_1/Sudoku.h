class Sudoku
{
  public:
    static const int  N = 9;
    void enterDigits();
    bool solve(int r, int c); // r || R is row; c || C is column
    void print();
    bool validateBoard();
    
  private:
    int board[N][N];
    bool findEmptyCell(int arr[][N], int& r, int& c);
    bool isROk(int arr[][N], int r, int i);
    bool isCOk(int arr[][N], int c, int i);
    bool isBoxOk(int arr[][N], int boxR, int boxC, int i);
    bool isAllOk(int arr[][N], int r, int c, int i);
};