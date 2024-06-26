/*
https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 03
/*

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0;
        int j = cols - 1;

        while(i < rows && j >= 0)
        {
            if(target > matrix[i][j])
                i++;
            else if(target < matrix[i][j])
                j--;
            else
                return true;
        }

        return false;
    }
};

*/

// Solution # 02
/*

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left  = 0;
        int right = (rows * cols) - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            int midElem = matrix[mid/cols][mid%cols];

            if(target == midElem)
                return true;

            if(target > midElem)
                left = mid + 1;
            else if(target < midElem)
                right = mid - 1;
        }

        return false;
    }
};

*/

// Solution # 01
class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0;
    int bot = rows - 1;

    while (top <= bot)
    {
      int mid = (top + bot) / 2;

      if (target > matrix[mid][cols - 1])
        top = mid + 1;
      else if (target < matrix[mid][0])
        bot = mid - 1;
      else
        break;
    }

    if (top > bot)
      return false;

    int left = 0;
    int right = cols - 1;
    int row = (top + bot) / 2;

    while (left <= right)
    {
      int mid = (left + right) / 2;

      if (target > matrix[row][mid])
        left = mid + 1;
      else if (target < matrix[row][mid])
        right = mid - 1;
      else
        return true;
    }

    return false;
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> matrix = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}};
  int target = 3;

  cout << obj.searchMatrix(matrix, target) << endl;

  return 0;
}