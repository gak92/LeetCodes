/*
https://leetcode.com/problems/combination-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<vector<int>> res;

  void dfs(int k, int target, int start, vector<int> &temp, int total)
  {
    if (k == 0 && total == target)
    {
      res.push_back(temp);
      return;
    }

    if (k == 0 || start > 9 || total > target)
      return;

    temp.push_back(start);
    dfs(k - 1, target, start + 1, temp, total + start);

    temp.pop_back();
    dfs(k, target, start + 1, temp, total);
  }

public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> temp;
    int start = 1;
    int total = 0;

    dfs(k, n, start, temp, total);
    return res;
  }
};

int main()
{
  Solution *obj = new Solution();
  vector<vector<int>> result = obj->combinationSum3(3, 9);

  for (auto i : result)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}