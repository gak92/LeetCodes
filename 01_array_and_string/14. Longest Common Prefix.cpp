/*
https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    string res = "";

    for (int i = 0; i < strs[0].length(); i++)
    {
      for (auto &s : strs)
      {
        if (i == s.length() || strs[0][i] != s[i])
          return res;
      }

      res += strs[0][i];
    }

    return res;
  }
};

int main()
{
  return 0;
}