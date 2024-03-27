/*
https://leetcode.com/problems/permutations/description/
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> res;
  int n;
  unordered_set<int> set;

  void solve(vector<int> &nums, vector<int> &temp)
  {
    if (temp.size() == n) // base case
    {
      res.push_back(temp);
      return;
    }

    for (int i = 0; i < n; i++)
    {
      if (set.find(nums[i]) == set.end())
      {
        set.insert(nums[i]);
        temp.push_back(nums[i]);

        solve(nums, temp); // recursive calls

        set.erase(nums[i]); // backtracking
        temp.pop_back();
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    n = nums.size();
    vector<int> temp;
    solve(nums, temp);
    return res;
  }
};

/*
Solution 2: Using swap method

class Solution {
public:
    int n;
    vector<vector<int>> res;

    void solve(int idx, vector<int>& nums)
    {
        if(idx == n)                        // base case
        {
            res.push_back(nums);
            return;
        }

        for(int i=idx; i<n; i++)
        {
            swap(nums[i], nums[idx]);
            solve(idx+1, nums);             // recursive calls
            swap(nums[i], nums[idx]);       // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);
        return res;
    }
};

*/

int main()
{
  Solution obj;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = obj.permute(nums);
  for (auto x : res)
  {
    for (auto y : x)
      cout << y << " ";
    cout << endl;
  }
  return 0;
}