/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n == 0 || n == 1)
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = max(prices[1] - prices[0], 0);

        for(int i=2; i<n; i++) {
            dp[i] = dp[i-1];
            for(int j=0; j<i; j++) {
                int today_profit = prices[i] - prices[j];
                int prev_profit = j>=2 ? dp[j-2] : 0;

                dp[i] = max(dp[i], today_profit + prev_profit);
            }
        }

        return dp[n-1];
    }
};
*/

class Solution
{
private:
  int dp[5001][2];
  int solve(vector<int> &prices, int n, int day, bool buy)
  {
    if (day >= n)
      return 0;

    if (dp[day][buy] != -1)
      return dp[day][buy];

    int profit = 0;

    if (buy)
    {
      int take = solve(prices, n, day + 1, false) - prices[day];
      int not_take = solve(prices, n, day + 1, true);
      profit = max({profit, take, not_take});
    }
    else
    {
      int sell = prices[day] + solve(prices, n, day + 2, true);
      int not_sell = solve(prices, n, day + 1, false);
      profit = max({sell, not_sell, profit});
    }

    return dp[day][buy] = profit;
  }

public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    memset(dp, -1, sizeof(dp));

    return solve(prices, n, 0, true);
  }
};

int main()
{
  Solution obj;
  vector<int> prices = {1, 2, 3, 0, 2};
  cout << obj.maxProfit(prices) << endl;
  return 0;
}