/*
https://leetcode.com/problems/palindrome-number/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
      return false;

    long div = 1;
    while (x >= div * 10)
      div = div * 10;

    while (x)
    {
      int right = x % 10;
      int left = x / div;
      cout << "right: " << right << ", left: " << left << endl;

      if (left != right)
        return false;

      x = (x % div) / 10;

      div = div / 100;
    }

    return true;
  }
};

int main()
{
  int x = 121;
  Solution s;
  cout << s.isPalindrome(x) << endl;

  return 0;
}