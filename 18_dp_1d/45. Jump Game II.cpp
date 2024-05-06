/*
https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 2 - Tabulation
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);

        dp[0] = 0;

        for(int i=1; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(j+nums[j] >= i)
                    dp[i] = min(dp[i], 1+dp[j]);
            }
        }

        return dp[n-1];
    }
};

*/

// Solution # 1 - Recursive + Memoization
/*
class Solution {
private:
    int solve(vector<int>& nums, int n, int idx, vector<int>& dp)
    {
        if(idx >= n-1)
            return 0;

        // int minJump = 10001;
        if(dp[idx] != 10001)
            return dp[idx];

        for(int i=1; i<=nums[idx]; i++) {
            dp[idx] =  min(dp[idx], 1 + solve(nums, n, idx + i, dp));
        }

        return dp[idx];
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);

        return solve(nums, n, 0, dp);
    }
};

*/

// Greedy Solution - O(n)

// Greedy optimal solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;

        while(r < n-1) {
            int farthest = 0;
            for(int i=l; i<=r; i++) {
                farthest = max(farthest, i+nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main()
{
  vector<int> nums = {2, 3, 1, 1, 4};
  Solution obj;
  cout << obj.jump(nums) << endl;
  return 0;
}