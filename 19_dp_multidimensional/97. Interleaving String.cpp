/*
https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 - (Recursion + Memoization)

class Solution {
private:
    int n, m, N;
    int dp[101][101][201];
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3)
    {
        if(i == n && j == m && k == N)
            return true;

        if(k >= N)
            return false;

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        bool res = false;
        if(s1[i] == s3[k])
            res = solve(i+1, j, k+1, s1, s2, s3);
        if(res == true)
            return dp[i][j][k] = res;

        if(s2[j] == s3[k])
            res = solve(i, j+1, k+1, s1, s2, s3);

        return dp[i][j][k] = res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        N = s3.length();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s1, s2, s3);
    }
};
