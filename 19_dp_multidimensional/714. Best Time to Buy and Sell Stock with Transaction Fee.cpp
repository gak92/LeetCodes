/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int solve(vector<int> &prices, int fee)
  {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
      for (int buy = 0; buy <= 1; buy++)
      {
        int profit = 0;
        if (buy)
        {
          profit = max((dp[i + 1][0] - prices[i]), (dp[i + 1][1]));
        }
        else
        {
          profit = max((dp[i + 1][1] + prices[i] - fee), (dp[i + 1][0]));
        }

        dp[i][buy] = profit;
      }
    }

    return dp[0][1];
  }

public:
  int maxProfit(vector<int> &prices, int fee)
  {

    return solve(prices, fee);
  }
};

/*
class Solution {
// Time Limit Exceed
private:
    int FEE;
    int dp[50001][2];

    int solve(vector<int>& prices, int n, int day, bool buy) {
        if(day >= n)
            return 0;

        if(dp[day][buy] != -1)
            return dp[day][buy];

        int profit = 0;

        if(buy) {
            int take = solve(prices, n, day+1, false) - prices[day];
            int not_take = solve(prices, n, day+1, true);
            profit = max({profit, take, not_take});
        }
        else {
            int sell = prices[day] + solve(prices, n, day+1, true) - FEE;
            int not_sell = solve(prices, n, day+1, false);
            profit = max({profit, sell, not_sell});
        }

        return dp[day][buy] = profit;
    }


public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        FEE = fee;
        memset(dp, -1, sizeof(dp));

        return solve(prices, n, 0, true);
    }
};
*/
int main()
{
  Solution s;
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int fee = 2;

  cout << s.maxProfit(prices, fee) << endl;
  return 0;
}