/*
https://leetcode.com/problems/rotate-image/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;

        while(l < r)
        {
            for(int i=0; i<r-l; i++)
            {
                int top = l;
                int bottom = r;

                // save top left
                int topLeft = matrix[top][l + i];

                // move bottom left to top left
                matrix[top][l + i] = matrix[bottom - i][l];

                // move bottom right to bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // move top right to bottom right
                matrix[bottom][r - i] = matrix[top + i][r];

                // move top left to top right
                matrix[top + i][r] = topLeft;
            }

            l++;
            r--;
        }
    }
};

*/

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