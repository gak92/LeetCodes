/*
https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150
*/

// Solution # 01 (Dynamic Programming - Bottom Up)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);

        for(int i=0; i<n; i++)
            dp[i] = triangle[n-1][i];

        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};
