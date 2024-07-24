/*
https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 - (Recursion + Memoization)

class Solution {
private:
    int m, n;
    int dp[101][101];

    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 1)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(grid, i, j+1);
        int down  = solve(grid, i+1, j);

        return dp[i][j] = right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(obstacleGrid, 0, 0);
    }
};
