/*
https://leetcode.com/problems/surrounded-regions/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j, int& rows, int& cols)
    {
        if(i<0 || j<0 || i>=rows || j>=cols || board[i][j] != 'O')
            return;

        board[i][j] = 'T';
        dfs(board, i+1,  j, rows, cols);
        dfs(board, i-1,  j, rows, cols);
        dfs(board, i, j+1, rows, cols);
        dfs(board, i, j-1, rows, cols);
    }

public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == 'O' && (i==0 || j==0 || i==rows-1 || j==cols-1))
                    dfs(board, i, j, rows, cols);
            }
        }

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == 'T')
                    board[i][j] = 'O';

            }
        }

    }
};

*/

class Solution
{
private:
  void dfs(vector<vector<char>> &board, int i, int j, int m, int n)
  {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
      return;

    board[i][j] = 'T';

    dfs(board, i - 1, j, m, n);
    dfs(board, i + 1, j, m, n);
    dfs(board, i, j - 1, m, n);
    dfs(board, i, j + 1, m, n);
  }

public:
  void solve(vector<vector<char>> &board)
  {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
      dfs(board, i, 0, m, n);
      dfs(board, i, n - 1, m, n);
    }

    for (int j = 0; j < n; j++)
    {
      dfs(board, 0, j, m, n);
      dfs(board, m - 1, j, m, n);
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == 'O')
          board[i][j] = 'X';

        if (board[i][j] == 'T')
          board[i][j] = 'O';
      }
    }
  }
};

int main()
{
  vector<vector<char>> board = {
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'O', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'}};

  Solution s;
  s.solve(board);
  for (auto row : board)
  {
    for (auto cell : row)
    {
      cout << cell << " ";
    }
    cout << endl;
  }

  return 0;
}