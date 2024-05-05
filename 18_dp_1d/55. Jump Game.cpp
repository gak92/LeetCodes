/*
https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 03 - Optimal Solution
// Bottom UP
class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int maxReachable = 0;

    for (int i = 0; i < n; i++)
    {
      if (i > maxReachable)
        return false;

      maxReachable = max(maxReachable, i + nums[i]);
    }

    return true;
  }
};

// Solution # 02 - Bottom Up
/*
// Bottom UP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);

        // state definition
        // dp[i] = true     (it means i can reach to the ith index)

        dp[0] = true;

        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(dp[j] == true && j+nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};
*/

// Solution # 01 - Recursion + Memoization
/*
class Solution {
private:
    int dp[10001];
    bool solve(vector<int>& nums, int n, int idx)
    {
        if(idx == n-1)
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(int i=1; i<=nums[idx]; i++) {
            if(solve(nums, n, idx+i))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));
        return solve(nums, n, 0);
    }
};
*/
int main()
{
  vector<int> nums = {2, 3, 1, 1, 4};
  Solution s;
  cout << s.canJump(nums) << endl;

  return 0;
}