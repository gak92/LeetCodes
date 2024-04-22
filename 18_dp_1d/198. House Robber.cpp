/*
https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

  // Solution # 01 - DP Top Down Approach (Recursion + Memoization)
  // private:
  //     int dp[101];
  //     int solve(vector<int>& nums, int idx, int n) {
  //         if(idx >= n)
  //             return 0;

  //         if(dp[idx] != -1)
  //             return dp[idx];

  //         int steal = nums[idx] + solve(nums, idx+2, n);
  //         int skip  = solve(nums, idx+1, n);

  //         return dp[idx] = max(steal, skip);
  //     }
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();

    // Solution # 02
    if (n == 1)
      return nums[0];
    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; i++)
    {
      int steal = nums[i - 1] + dp[i - 2];
      int skip = dp[i - 1];

      dp[i] = max(steal, skip);
    }

    return dp[n];

    // Solution # 01
    // memset(dp, -1, sizeof(dp));
    // return solve(nums, 0, n);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 7, 9, 3, 1};
  cout << s.rob(nums) << endl;

  return 0;
}