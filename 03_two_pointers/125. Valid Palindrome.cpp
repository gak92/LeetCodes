/*
https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool isAlphaNum(char c)
  {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

public:
  bool isPalindrome(string s)
  {
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
    {
      while (l < r && !isAlphaNum(s[l]))
        l++;

      while (l < r && !isAlphaNum(s[r]))
        r--;

      if (tolower(s[l]) != tolower(s[r]))
        return false;

      l++;
      r--;
    }

    return true;
  }
};

int main()
{
  Solution s;
  string str = "A man, a plan, a canal: Panama";
  cout << s.isPalindrome(str);

  return 0;
}