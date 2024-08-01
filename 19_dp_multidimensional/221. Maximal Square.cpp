/*
https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 - (Recursion + Memoization)

class Solution {
private:
    int m, n;
    int maxi;
    
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= m || j >= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(matrix, i, j+1, dp);
        int diag  = solve(matrix, i+1, j+1, dp);
        int down  = solve(matrix, i+1, j, dp);

        if(matrix[i][j] == '1') {
            int res = 1 + min({right, diag, down});
            maxi = max(maxi, res);
            return dp[i][j] = res;
        }
        else {
            return dp[i][j] = 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        maxi = 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));        

        solve(matrix, 0, 0, dp);
        return maxi*maxi;
    }
};
