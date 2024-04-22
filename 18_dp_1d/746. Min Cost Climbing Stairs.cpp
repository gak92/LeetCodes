/*
https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  // Solution # 01 - Top Down Recursion with Memoization
  // private:
  //     int dp[1001];
  //     int solve(int idx, vector<int>& cost) {
  //         if(idx >= cost.size())
  //             return 0;

  //         if(dp[idx] != -1)
  //             return dp[idx];

  //         int a = cost[idx] + solve(idx + 1, cost);
  //         int b = cost[idx] + solve(idx + 2, cost);

  //         return  dp[idx] = min(a,b);
  //     }

public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();

    // Solution # 01
    // memset(dp, -1, sizeof(dp));
    // return min(solve(0, cost), solve(1, cost));

    // Solution # 02 (Bottom Up Approach)
    if (n == 2)
      return min(cost[0], cost[1]);

    for (int i = 2; i < n; i++)
    {
      cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
    }

    return min(cost[n - 1], cost[n - 2]);
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<int> cost = {10, 15, 20};
  cout << sol->minCostClimbingStairs(cost) << endl;
  delete sol;

  return 0;
}