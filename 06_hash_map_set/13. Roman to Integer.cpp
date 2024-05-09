/*
https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    int res = 0;
    unordered_map<char, int> roman{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    for (int i = 0; i < s.length(); i++)
    {
      if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]])
        res -= roman[s[i]];
      else
        res += roman[s[i]];
    }

    return res;
  }
};

int main()
{
  string s = "III";
  Solution roman;
  cout << roman.romanToInt(s) << endl;

  return 0;
}