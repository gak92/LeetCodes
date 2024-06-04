/*
https://leetcode.com/problems/combination-sum-iv/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int n;
  int dp[201][1001];

  int solve(int idx, vector<int> &nums, int target)
  {
    if (target == 0)
      return 1;

    if (idx >= n || target < 0)
      return 0;

    if (dp[idx][target] != -1)
      return dp[idx][target];

    int res = 0;

    for (int i = 0; i < n; i++)
    {
      int take_i = solve(0, nums, target - nums[i]);
      res += take_i;
    }

    return dp[idx][target] = res;
  }

public:
  int combinationSum4(vector<int> &nums, int target)
  {
    n = nums.size();

    memset(dp, -1, sizeof(dp));

    return solve(0, nums, target);
  }
};

int main()
{
  Solution obj;
  vector<int> nums = {1, 2, 3};
  int target = 4;

  cout << obj.combinationSum4(nums, target) << endl;

  return 0;
}