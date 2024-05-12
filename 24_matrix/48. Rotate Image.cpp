/*
https://leetcode.com/problems/rotate-image/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = m;

    // transpose of the matrix
    for (int i = 0; i < m; i++)
    {
      for (int j = i; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // reverse the row
    for (int i = 0; i < m; i++)
    {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

int main()
{
  Solution rotateImage;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotateImage.rotate(matrix);
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