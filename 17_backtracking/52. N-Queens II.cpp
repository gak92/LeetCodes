/*
https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int N;
  int res;
  unordered_set<int> columns;
  unordered_set<int> leftDiag;
  unordered_set<int> rightDiag;

  void solve(vector<string> &board, int row)
  {
    if (row >= N)
    {
      res++;
      return;
    }

    for (int col = 0; col < N; col++)
    {
      if (columns.find(col) != columns.end() ||
          leftDiag.find(row - col) != leftDiag.end() ||
          rightDiag.find(row + col) != rightDiag.end()) // attack
        continue;

      board[row][col] = 'Q';
      columns.insert(col);
      leftDiag.insert(row - col);
      rightDiag.insert(row + col);

      solve(board, row + 1);

      board[row][col] = '.';
      columns.erase(col);
      leftDiag.erase(row - col);
      rightDiag.erase(row + col);
    }
  }

public:
  int totalNQueens(int n)
  {
    N = n;
    vector<string> board(n, string(n, ','));

    solve(board, 0);

    return res;
  }
};

int main()
{
  Solution s;
  cout << s.totalNQueens(4) << endl;

  return 0;
}