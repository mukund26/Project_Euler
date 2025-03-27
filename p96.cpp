#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

class Solution
{
  vector<int> row, col, box;

public:
  bool isValid(int r, int c, char ch)
  {
    int val = 1 << (ch - '0');
    if (row[r] & val)
    {
      return false;
    }
    if (col[c] & val)
    {
      return false;
    }
    if (box[3 * (r / 3) + (c / 3)] & val)
    {
      return false;
    }
    return true;
  }

  bool recur(vector<vector<char>> &board, int r, int c)
  {
    if (r == 8 && c == 9)
    {
      return true;
    }
    if (c == 9)
    {
      return recur(board, r + 1, 0);
    }
    if (board[r][c] != '.')
    {
      return recur(board, r, c + 1);
    }
    for (char ch = '1'; ch <= '9'; ch++)
    {
      if (isValid(r, c, ch))
      {
        int val = 1 << (ch - '0');
        row[r] |= val;
        col[c] |= val;
        box[3 * (r / 3) + (c / 3)] |= val;
        board[r][c] = ch;
        if (recur(board, r, c + 1))
        {
          return true;
        }
        row[r] &= ~val;
        col[c] &= ~val;
        box[3 * (r / 3) + (c / 3)] &= ~val;
        board[r][c] = '.';
      }
    }
    return false;
  }

  int solveSudoku(vector<vector<char>> &board)
  {
    row.assign(9, 0);
    col.assign(9, 0);
    box.assign(9, 0);
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        if (board[i][j] != '.')
        {
          int val = 1 << (board[i][j] - '0');
          row[i] |= val;
          col[j] |= val;
          box[3 * (i / 3) + (j / 3)] |= val;
        }
      }
    }
    recur(board, 0, 0);
    return (board[0][0] - '0') * 100 + (board[0][1] - '0') * 10 + (board[0][2] - '0');
  }
};

int main()
{

  ifstream file("sudoku.txt");
  string line;
  vector<vector<char>> board(9, vector<char>(9));
  Solution s;
  int sum = 0;

  while (getline(file, line))
  {
    for (int i = 0; i < 9; i++)
    {
      getline(file, line);
      for (int j = 0; j < 9; j++)
      {
        board[i][j] = line[j] == '0' ? '.' : line[j];
      }
    }
    sum += s.solveSudoku(board);
  }

  cout << sum << endl;

  return 0;
}