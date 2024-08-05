/*

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
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        int currDay   = 0;
        int transactionLeft = k;
        bool buy = true;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(transactionLeft+1, -1)));

        return solve(prices, currDay, transactionLeft, buy, dp);
    }
};


// Solution # 02 - Tabulation

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactionLeft = k; 
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(transactionLeft+1, 0)));

        for(int currDay=n-1; currDay>=0; currDay--)
        {
            for(int buy=0; buy<2; buy++)
            {
                for(int tleft=1; tleft<=transactionLeft; tleft++)
                {
                    int profit = INT_MIN;
                    if(buy) {
                        int buyProfit = dp[currDay+1][0][tleft] - prices[currDay];
                        int ignoreBuy = dp[currDay+1][1][tleft];
                        profit = max(buyProfit, ignoreBuy);
                    }
                    else {
                        int sellProfit = dp[currDay+1][1][tleft-1] + prices[currDay];
                        int ignoreSell = dp[currDay+1][0][tleft];
                        profit = max(sellProfit, ignoreSell);
                    }
                    dp[currDay][buy][tleft] = profit;
                }
            }
        }

        return dp[0][1][transactionLeft];
    }
};
