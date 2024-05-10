/*
https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1) // edge case
      return s;

    string res = "";
    int increment = 2 * (numRows - 1); // for each row character at increment

    // traverse each row
    for (int row = 0; row < numRows; row++)
    {

      // traverse the string for each row
      for (int i = row; i < s.length(); i += increment)
      {
        res += s[i];
        if (row > 0 && row < numRows - 1 && i + increment - 2 * row < s.length())
          res += s[i + increment - 2 * row];
      }
    }

    return res;
  }
};

int main()
{
  return 0;
}