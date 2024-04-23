/*
https://leetcode.com/problems/domino-and-tromino-tiling/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int M = 1000000007;
  // Solution#01 - Recursive + Memoization
  // int dp[1001];

  // int solve(int n) {
  //     if(n == 1 || n == 2)
  //         return n;

  //     if(dp[n] != -1)
  //         return dp[n];

  //     if(n == 3)
  //         return 5;

  //     return dp[n] = (2*solve(n-1) % M + solve(n-3) % M) % M;
  // }
public:
  int numTilings(int n)
  {
    // Solution # 01
    // memset(dp, -1, sizeof(dp));
    // return solve(n);

    // Solution # 02
    if (n == 1 || n == 2)
      return n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++)
    {
      dp[i] = (2 * dp[i - 1] % M + dp[i - 3] % M) % M;
    }

    return dp[n];
  }
};

int main()
{
  int n = 4;
  Solution s;
  cout << s.numTilings(n) << endl;

  return 0;
}