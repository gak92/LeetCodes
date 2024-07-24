/*
https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 (Recursion + Memoization) (Top Down Approach)
class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n,  vector<vector<int>>& dp)
    {
        if(i == m-1 && j == n-1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == m-1)
            return dp[i][j] = grid[i][j] + solve(grid, i, j+1, m, n, dp);
        else if(j == n-1)
            return dp[i][j] = grid[i][j] + solve(grid, i+1, j, m, n, dp);
        else
            return dp[i][j] = grid[i][j] + min(solve(grid, i, j+1, m, n, dp), solve(grid, i+1, j, m, n, dp));

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(grid, 0, 0, m, n, dp);
    }
};
