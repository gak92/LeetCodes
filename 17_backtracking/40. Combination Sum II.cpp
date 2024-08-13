/*
https://leetcode.com/problems/combination-sum-ii/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<vector<int>> res;

  void dfs(vector<int> &candidates, int target, vector<int> &temp, int start, int total)
  {
    if (total == target)
    {
      res.push_back(temp);
      return;
    }

    if (start >= candidates.size() || total > target)
      return;

    temp.push_back(candidates[start]);
    dfs(candidates, target, temp, start + 1, total + candidates[start]);

    temp.pop_back();
    while (start + 1 < candidates.size() && candidates[start] == candidates[start + 1])
      start++;
    dfs(candidates, target, temp, start + 1, total);
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<int> temp;
    int total = 0;
    int start = 0;

    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, temp, start, total);

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  vector<vector<int>> res = s.combinationSum2(candidates, target);
  for (auto i : res)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}



// Method # 02 (using for loop)

class Solution {
private:
    void solve(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int idx)
    {
        if(target < 0)
            return;
        if(target == 0) {
            res.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) // skip duplicate
                continue;

            curr.push_back(candidates[i]);  // DO
            solve(candidates, target-candidates[i], curr, res, i+1);    // Explore
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, curr, res, 0);

        return res;
    }
};


