/*
https://leetcode.com/problems/longest-palindrome/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 01

class Solution
{
public:
  int longestPalindrome(string s)
  {
    int n = s.length();
    unordered_set<char> set;
    int res = 0;

    for (auto &ch : s)
    {
      if (set.count(ch))
      {
        res += 2;
        set.erase(ch);
      }
      else
      {
        set.insert(ch);
      }
    }

    if (!set.empty())
      res++;

    return res;
  }
};

int main()
{
  Solution solution;
  cout << solution.longestPalindrome("abccccdd") << endl;

  return 0;
}
