/*

https://leetcode.com/problems/plus-one/description/
*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {

    for (int i = digits.size() - 1; i >= 0; i--)
    {
      if (digits[i] < 9)
      {
        digits[i] += 1;
        return digits;
      }
      else
      {
        digits[i] = 0;
      }
    }

    // in case input: [9,9,9]
    digits[0] = 1;
    digits.push_back(0);
    return digits;
  }
};

int main()
{
  vector<int> digits = {9, 9, 9};
  Solution obj;
  vector<int> res = obj.plusOne(digits);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << ", ";
  }
  cout << endl;
  return 0;
}