/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<string> res;
  unordered_map<char, string> mp{
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "pqrs"},
      {'8', "tuv"},
      {'9', "wxyz"}};

  void dfs(string digits, int idx, string temp)
  {
    if (idx == digits.length())
    {
      res.push_back(temp);
      return;
    }

    char ch = digits[idx]; // ch = '2'
    string str = mp[ch];   // str = 'abc'
    for (int i = 0; i < str.length(); i++)
    {
      temp.push_back(str[i]);
      dfs(digits, idx + 1, temp);
      temp.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits)
  {
    if (digits.length() == 0)
      return {};

    string temp = "";
    dfs(digits, 0, temp);

    return res;
  }
};

int main()
{
  Solution s;
  vector<string> res = s.letterCombinations("23");

  for (string str : res)
  {
    cout << str << " ";
  }
  cout << endl;

  return 0;
}