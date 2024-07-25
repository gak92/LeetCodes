/*
https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 - (Recursion + Memoization)
class Solution {
private:
    int dp[1001][1001];
    bool solve(string& s, int i, int j)
    {
        if(i >= j)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = solve(s, i+1, j-1);

        return dp[i][j] = 0;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int sp = 0;

        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(solve(s, i, j) && (j-i+1) > maxLen) {
                    maxLen = j - i + 1;
                    sp = i;
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};
