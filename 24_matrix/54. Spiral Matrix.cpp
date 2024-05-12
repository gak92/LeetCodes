/*
https://leetcode.com/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int m = matrix.size();    // rows
    int n = matrix[0].size(); // cols
    vector<int> res;

    int dir = 0; // direction
    int top = 0;
    int down = m - 1;
    int left = 0;
    int right = n - 1;

    /*
        dir 0 = left to right
        dir 1 = top to down
        dir 2 = right to left
        dir 3 = down to top
    */

    while (top <= down && left <= right)
    {
      if (dir == 0)
      { // left to right, constant = top
        for (int i = left; i <= right; i++)
          res.push_back(matrix[top][i]);
        top++;
      }

      if (dir == 1)
      { // top to down, constant = right
        for (int i = top; i <= down; i++)
          res.push_back(matrix[i][right]);
        right--;
      }

      if (dir == 2)
      { // right to left, constant = down
        for (int i = right; i >= left; i--)
          res.push_back(matrix[down][i]);
        down--;
      }

      if (dir == 3)
      { // down to top, constant = left
        for (int i = down; i >= top; i--)
          res.push_back(matrix[i][left]);
        left++;
      }

      dir++;
      if (dir == 4)
        dir = 0;
    }

    return res;
  }
};

int main()
{
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  vector<int> res = s.spiralOrder(matrix);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";

    return 0;
}