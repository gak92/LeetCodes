/*
https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 - Recursion + Memoization (Top Down)
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

// Solution # 02 - Tabulation (Bottom Up)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX-1);
        dp[0] = 0;

        for(int amnt=1; amnt<=amount; amnt++)
        {
            for(int coin : coins)
            {
                if(amnt - coin >= 0)
                    dp[amnt] = min(dp[amnt], dp[amnt - coin] + 1);
            }
        }

        return dp[amount] == INT_MAX-1 ? -1 : dp[amount]; 
    }
};
