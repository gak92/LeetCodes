/*
https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int i = s.length() - 1;
    int length = 0;

    while (s[i] == ' ')
      i--;

    while (i >= 0 && s[i] != ' ')
    {
      length++;
      i--;
    }

    return length;
  }
};

int main()
{
  string str = "Hello World";
  Solution s;
  cout << s.lengthOfLastWord(str) << endl;

  return 0;
}