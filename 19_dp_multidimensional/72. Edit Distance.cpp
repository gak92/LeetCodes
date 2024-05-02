/*
https://leetcode.com/problems/edit-distance/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
        {
          dp[i][j] = i + j;
        }
        else if (word1[i - 1] == word2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
      }
    }

    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }

    return dp[m][n];
  }
};

/*
class Solution {
private:
    int m, n;
    int dp[501][501];

    int solve(string s1, string s2, int m, int n) {
        if(m == 0 || n == 0) {
            return m + n;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        if(s1[m-1] == s2[n-1]) {
            return dp[m][n] = solve(s1, s2, m-1, n-1);
        }
        else {
            int insertChar  = 1 + solve(s1, s2, m, n-1);
            int deleteChar  = 1 + solve(s1, s2, m-1, n);
            int replaceChar = 1 + solve(s1, s2, m-1, n-1);

            return dp[m][n] = min({insertChar, deleteChar, replaceChar});
        }

        return -1;
    }

public:
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();

        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, m, n);
    }
};
*/

/*
class Solution {
private:
    int m, n;
    int dp[501][501];

    int solve(string s1, string s2, int i, int j) {
        if(i == m) {            // if word1 reach to the end
            return n - j;       // insert remaining character of word2
        }
        if(j == n) {            // if word2 reach to the end
            return m - i;       // delete remaining character of word1
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i+1, j+1);
        }
        else {
            int insertChar  = 1 + solve(s1, s2, i, j+1);
            int deleteChar  = 1 + solve(s1, s2, i+1, j);
            int replaceChar = 1 + solve(s1, s2, i+1, j+1);

            return dp[i][j] = min({insertChar, deleteChar, replaceChar});
        }

        return -1;
    }

public:
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();

        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};

*/

int main()
{
  Solution s;
  cout << s.minDistance("horse", "ros") << endl;

  return 0;
}