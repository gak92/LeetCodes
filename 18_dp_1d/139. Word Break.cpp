/*
https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int n;
  unordered_set<string> set;
  int dp[301];

  bool solve(int idx, string &s)
  {
    if (idx >= n)
      return true;

    if (dp[idx] != -1)
      return dp[idx];

    if (set.find(s) != set.end())
      return true;

    for (int l = 1; l <= n; l++)
    {
      string temp = s.substr(idx, l);
      if (set.find(temp) != set.end() && solve(idx + l, s))
        return dp[idx] = true;
    }

    return dp[idx] = false;
  }

public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    n = s.length();

    memset(dp, -1, sizeof(dp));

    for (string &word : wordDict)
      set.insert(word);

    return solve(0, s);
  }
};

int main()
{
  Solution s;
  vector<string> wordDict = {"leet", "code"};
  cout << s.wordBreak("leetcode", wordDict) << endl;

  return 0;
}