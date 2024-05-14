/*
https://leetcode.com/problems/game-of-life/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int countNeighbors(vector<vector<int>> &board, int r, int c)
  {
    int nbr = 0;
    int rows = board.size();
    int cols = board[0].size();

    for (int i = r - 1; i < r + 2; i++)
    {
      for (int j = c - 1; j < c + 2; j++)
      {
        // if(i>=0 && j>=0 && i<rows && j<cols && i != r && j != c )
        //     if(board[i][j] == 1 || board[i][j] == 3)
        //         nbr++;
        if ((i == r && j == c) || i < 0 || j < 0 || i == rows || j == cols)
          continue;

        if (board[i][j] == 1 || board[i][j] == 3)
          nbr++;
      }
    }

    return nbr;
  }

public:
  void gameOfLife(vector<vector<int>> &board)
  {
    int rows = board.size();
    int cols = board[0].size();

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        int nbr = countNeighbors(board, r, c);
        cout << "Nbr: (" << r << ", " << c << ")" << nbr << endl;
        if (board[r][c] == 1)
        { // living cells - 1
          if (nbr == 2 || nbr == 3)
            board[r][c] = 3;
        }
        else
        { // dead cells - 0
          if (nbr == 3)
            board[r][c] = 2;
        }
      }
    }

    // mark each cell 0(dies) or 1(live)
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        if (board[r][c] == 1)
          board[r][c] = 0;
        else if (board[r][c] == 2 || board[r][c] == 3)
          board[r][c] = 1;
      }
    }
  }
};

/*
    Original    |  New   |     State
        0           0           0
        1           0           1
        0           1           2
        1           1           3
*/

int main()
{
  Solution s;
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  s.gameOfLife(board);
  cout << "New Board:\n";
  for (auto row : board)
  {
    for (auto cell : row)
      cout << cell << " ";
    cout << endl;
  }

  return 0;
}