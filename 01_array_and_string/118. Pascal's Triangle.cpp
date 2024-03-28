/*
https://leetcode.com/problems/pascals-triangle/description/
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> triangle;

    // for creating rows
    for (int i = 0; i < numRows; i++)
    {
      vector<int> row(i + 1, 1);

      for (int j = 1; j < i; j++)
      {
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }

      triangle.push_back(row);
    }

    return triangle;
  }
};

int main()
{
  int numRows = 5;
  Solution s;
  vector<vector<int>> triangle = s.generate(numRows);
  for (int i = 0; i < triangle.size(); i++)
  {
    for (int j = 0; j < triangle[i].size(); j++)
    {
      cout << triangle[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}