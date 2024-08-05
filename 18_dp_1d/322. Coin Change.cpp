/*
https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
private:
    int solve(vector<int>& coins, int amount, vector<int>& dp)
    {
        if(amount == 0) return 0;
        if(amount < 0)  return -1;
        if(dp[amount] != -2) return dp[amount];

        int minCoins = INT_MAX;

        for(int coin : coins) {
            int res = solve(coins, amount - coin, dp);
            if(res >= 0 && res < minCoins)
                minCoins = 1 + res;
        }

        return dp[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2);
        return solve(coins, amount, dp);        
    }
};
