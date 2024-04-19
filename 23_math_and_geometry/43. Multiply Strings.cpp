/*
https://leetcode.com/problems/multiply-strings/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0")
      return "0";

    vector<int> res(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; i--)
    {
      for (int j = num2.size() - 1; j >= 0; j--)
      {
        res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        res[i + j] += res[i + j + 1] / 10;
        res[i + j + 1] %= 10;
      }
    }

    int k = 0;
    while (k < res.size() && res[k] == 0)
      k++;

    string ans = "";
    while (k < res.size())
    {
      ans.push_back(res[k] + '0');
      k++;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.multiply("123", "456") << endl;

  return 0;
}