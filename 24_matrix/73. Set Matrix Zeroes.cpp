/*
https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int x = 1; // first row
    int y = 1; // first col

    // checking for first row
    for (int c = 0; c < n; c++)
    {
      if (matrix[0][c] == 0)
        x = 0;
    }

    // checking for first column
    for (int r = 0; r < m; r++)
    {
      if (matrix[r][0] == 0)
        y = 0;
    }

    // checking zeros for remaining matrix
    for (int r = 1; r < m; r++)
    {
      for (int c = 1; c < n; c++)
      {
        if (matrix[r][c] == 0)
        {
          matrix[r][0] = 0;
          matrix[0][c] = 0;
        }
      }
    }

    // Now traverse first row and mark corresponding column to 0
    for (int c = 1; c < n; c++)
    {
      if (matrix[0][c] == 0)
      {
        for (int r = 1; r < m; r++)
        {
          matrix[r][c] = 0;
        }
      }
    }

    // Now traverse first column and mark corresponding row to 0
    for (int r = 1; r < m; r++)
    {
      if (matrix[r][0] == 0)
      {
        for (int c = 1; c < n; c++)
        {
          matrix[r][c] = 0;
        }
      }
    }

    // Now update first row and column
    if (x == 0)
    {
      for (int c = 0; c < n; c++)
      {
        matrix[0][c] = 0;
      }
    }

    if (y == 0)
    {
      for (int r = 0; r < m; r++)
      {
        matrix[r][0] = 0;
      }
    }
  }
};

int main()
{
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  Solution s;
  s.setZeroes(matrix);
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}