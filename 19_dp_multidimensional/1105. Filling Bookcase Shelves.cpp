/*
https://leetcode.com/problems/filling-bookcase-shelves/description/?envType=daily-question&envId=2024-07-31
*/

// Solution # 01 - (Recursion + Memoization)

class Solution {
private:
    int n;
    int WIDTH;
    int dp[1001][1001];

    int solve(vector<vector<int>>& books, int i, int remWidth, int maxHt)
    {
        if(i >= n)
            return maxHt;

        if(dp[i][remWidth] != -1)
            return dp[i][remWidth];

        int currBookW = books[i][0];
        int currBookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;
        
        if(currBookW <= remWidth) {
            keep = solve(books, i+1, remWidth - currBookW, max(maxHt, currBookH));
        }

        skip = maxHt + solve(books, i+1, WIDTH - currBookW, currBookH);

        return dp[i][remWidth] = min(keep, skip);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        n = books.size();
        WIDTH = shelfWidth;

        int remWidth = shelfWidth;
        return solve(books, 0, remWidth, 0);
    }
};
