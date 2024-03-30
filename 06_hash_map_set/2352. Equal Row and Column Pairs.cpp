/*
https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int equalPairs(vector<vector<int>> &grid)
  {
    int count = 0;
    map<vector<int>, int> umap;

    for (int row = 0; row < grid.size(); row++)
      umap[grid[row]]++;

    for (int col = 0; col < grid[0].size(); col++)
    {
      vector<int> temp;
      for (int row = 0; row < grid.size(); row++)
      {
        temp.push_back(grid[row][col]);
      }

      count += umap[temp];
    }

    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> v{{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  cout << s.equalPairs(v) << endl; // 1
  return 0;
}