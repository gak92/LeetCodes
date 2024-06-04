/*
https://leetcode.com/problems/n-queens/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02 (optimized)
/*

class Solution {
private:
    int N;
    vector<vector<string>> res;
    unordered_set<int> columns;
    unordered_set<int> diagonal;
    unordered_set<int> antiDiag;

    void solve(vector<string>& board, int row)
    {
        if(row >= N) {
            res.push_back(board);
            return;
        }

        for(int col=0; col<N; col++)
        {
            if(columns.find(col) != columns.end() ||
                diagonal.find(row+col) != diagonal.end() ||
                antiDiag.find(row-col) != antiDiag.end())
                continue;

            columns.insert(col);
            diagonal.insert(row+col);
            antiDiag.insert(row-col);
            board[row][col] = 'Q';

            solve(board, row + 1);

            columns.erase(col);
            diagonal.erase(row+col);
            antiDiag.erase(row-col);
            board[row][col] = '.';

        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return res;
    }
};

*/

// Solution # 01

class Solution
{
private:
  int N;
  vector<vector<string>> res;

  bool isValid(vector<string> &board, int row, int col)
  {
    // check upward
    for (int i = row - 1; i >= 0; i--)
    {
      if (board[i][col] == 'Q')
        return false;
    }

    // check upward left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
      if (board[i][j] == 'Q')
        return false;
    }

    // check upward right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
      if (board[i][j] == 'Q')
        return false;
    }

    return true;
  }

  void solve(vector<string> &board, int row)
  {
    if (row >= N)
    {
      res.push_back(board);
      return;
    }

    for (int col = 0; col < N; col++)
    {
      if (isValid(board, row, col))
      {
        board[row][col] = 'Q'; // do
        solve(board, row + 1); // explore
        board[row][col] = '.'; // backtrack
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n)
  {
    N = n;
    vector<string> board(n, string(n, '.'));

    solve(board, 0);

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<string>> res = s.solveNQueens(4);

  for (auto v : res)
  {
    for (auto s : v)
    {
      cout << s << endl;
    }
    cout << endl;
  }

  return 0;
}