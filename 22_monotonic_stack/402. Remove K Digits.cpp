/*
https://leetcode.com/problems/remove-k-digits/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    string res = "";
    int n = num.length();

    for (int i = 0; i < n; i++)
    {
      while (res.length() > 0 && res.back() > num[i] && k > 0)
      {
        res.pop_back();
        k--;
      }
      // handle "0" prefix case
      if (res.length() > 0 || num[i] != '0')
        res.push_back(num[i]);
    }

    while (res.length() > 0 && k > 0)
    {
      res.pop_back();
      k--;
    }

    return res == "" ? "0" : res;
  }
};

int main()
{

  Solution s;
  string num = "1432219";
  int k = 3;
  cout << s.removeKdigits(num, k) << endl;
  return 0;
}