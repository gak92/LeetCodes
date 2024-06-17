/*
https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    string res = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int total = 0;
    int carry = 0;

    while (i >= 0 || j >= 0)
    {
      total = carry;
      if (i >= 0)
      {
        total += a[i] - '0';
        i--;
      }

      if (j >= 0)
      {
        total += b[j] - '0';
        j--;
      }

      res = to_string(total % 2) + res;
      carry = total / 2;
    }

    if (carry)
      res = "1" + res;

    return res;
  }
};

int main()
{
  Solution s;
  string a = "11";
  string b = "1";
  cout << s.addBinary(a, b) << endl;

  return 0;
}