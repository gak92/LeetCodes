/*

https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
  string gcdOfStrings(string str1, string str2)
  {

    // if str2 > str1, swap str1 & str2
    if (str2.length() > str1.length())
    {
      return gcdOfStrings(str2, str1);
    }

    // if both strings are equal
    if (str1 == str2)
    {
      return str2;
    }

    // now short the str1 if it starts with str2
    if (str1.compare(0, str2.length(), str2) == 0)
    {
      return gcdOfStrings(str1.substr(str2.length()), str2);
    }

    return "";
  }
};

int main()
{
  Solution s;
  string str1 = "ABCABC";
  string str2 = "ABC";
  cout << s.gcdOfStrings(str1, str2) << endl;
  return 0;
}