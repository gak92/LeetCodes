/*
https://leetcode.com/problems/combination-sum/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02
class Solution
{
private:
  vector<vector<int>> res;

  void dfs(vector<int> &candidates, int target, int start, vector<int> &temp, int total)
  {
    if (total == target)
    {
      res.push_back(temp);
      return;
    }

    if (total > target)
      return;

    // if(start >= candidates.size() || total > target)                 // 0, 0, 0, 0
    //     return;

    // temp.push_back(candidates[start]);                                   // [2, 2, 2]
    // dfs(candidates, target, start, temp, total+candidates[start]);      // total = 6

    // temp.pop_back();                                                    // [2,2,2] total = 6
    // dfs(candidates, target, start+1, temp, total);

    for (int i = start; i < candidates.size(); i++)
    {
      temp.push_back(candidates[i]);
      dfs(candidates, target, i, temp, total + candidates[i]);
      temp.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<int> temp;

    dfs(candidates, target, 0, temp, 0);

    return res;
  }
};

// Solution # 01
/*

class Solution {
private:
    vector<vector<int>> res;

    void dfs(vector<int>& candidates, int target, int start, vector<int>& temp, int total) {
        if(total == target) {
            res.push_back(temp);
            return;
        }

        if(start >= candidates.size() || total > target)                 // 0, 0, 0, 0
            return;

        temp.push_back(candidates[start]);                                   // [2, 2, 2, 2]
        dfs(candidates, target, start, temp, total+candidates[start]);      // total = 8

        temp.pop_back();
        // if(start+1)
        dfs(candidates, target, start+1, temp, total);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        dfs(candidates, target, 0, temp, 0);

        return res;
    }
};

*/
int main()
{
  Solution s;
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;

  vector<vector<int>> res = s.combinationSum(candidates, target);
  for (auto v : res)
  {
    for (auto i : v)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}