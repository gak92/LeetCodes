/*
https://leetcode.com/problems/climbing-stairs/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 03 (Dynamic Programming - Bottom Up Approach - Optimized)
class Solution
{
  // Bottop Up
public:
  int climbStairs(int n)
  {
    if (n == 1 || n == 2)
      return n;

    int first = 1;
    int second = 2;
    int res;

    for (int i = 3; i <= n; i++)
    {
      res = first + second;
      first = second;
      second = res;
    }

    return res;
  }
};

// Solution # 02 (Dynamic Programming - Bottom Up Approach)
/*
class Solution {
// Bottop Up
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);

        if(n == 0 || n == 1)
            return n;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
*/

// Solution # 01 (Dynamic Programming - Top Down Approach)
/*
class Solution {
private:

    int solve(int n, vector<int>& dp) {
        if(n < 0) return 0;
        if(dp[n] != -1)
            return dp[n];
        if(n == 0) return 1;

        int stepOne = solve(n-1, dp);
        int stepTwo = solve(n-2, dp);
        dp[n] = stepOne + stepTwo;

        return dp[n];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};

*/
int main()
{
  Solution s;
  cout << s.climbStairs(3) << endl;

  return 0;
}