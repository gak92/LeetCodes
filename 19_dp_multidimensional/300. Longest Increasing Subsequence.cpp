/*
https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int n;
  int dp[2501][2501];

  int solve(vector<int> &nums, int i, int prev)
  {
    if (i >= n)
      return 0;

    if (prev != -1 && dp[i][prev] != -1)
      return dp[i][prev];

    int take = 0;
    if (prev == -1 || nums[i] > nums[prev])
      take = 1 + solve(nums, i + 1, i);

    int skip = solve(nums, i + 1, prev);

    if (prev != -1)
      dp[i][prev] = max(take, skip);

    return max(take, skip);
  }

public:
  int lengthOfLIS(vector<int> &nums)
  {
    n = nums.size();

    memset(dp, -1, sizeof(dp));

    return solve(nums, 0, -1);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << s.lengthOfLIS(nums) << endl;

  return 0;
}