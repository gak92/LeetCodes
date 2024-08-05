/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 - (Recursion + Memoization)

class Solution {
private:
    int n;
    int solve(vector<int>& prices, int currDay, int transactionLeft, bool buy, vector<vector<vector<int>>>& dp)
    {
        if(currDay >= prices.size() || transactionLeft <= 0)
            return 0;

        if(dp[currDay][buy][transactionLeft] != -1)
            return dp[currDay][buy][transactionLeft];

        int res = INT_MIN;

        if(buy) {
            int buyProfit = solve(prices, currDay+1, transactionLeft, 0, dp) - prices[currDay];
            int ignoreBuy = solve(prices, currDay+1, transactionLeft, 1, dp);
            res = max(buyProfit, ignoreBuy);
        }
        else {
            int sellProfit = solve(prices, currDay+1, transactionLeft-1, 1, dp) + prices[currDay];
            int ignoreSell = solve(prices, currDay+1, transactionLeft, 0, dp);
            res = max(sellProfit, ignoreSell);
        }

        dp[currDay][buy][transactionLeft] = res;
        return dp[currDay][buy][transactionLeft];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currDay   = 0;
        int transactionLeft = 2;
        bool buy = true;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(transactionLeft+1, -1)));

        return solve(prices, currDay, transactionLeft, buy, dp);
    }
};
