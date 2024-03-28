/*
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int left = 0;
    int right = 0;
    int count = 0;
    int res = 0;
    string vowels = "aeiou";

    while (right < k)
    {
      if (vowels.find(s[right]) != string::npos)
        count++;
      right++;
    }
    res = count;
    while (right < s.length())
    {
      if (vowels.find(s[right]) != string::npos)
        count++;

      if (vowels.find(s[left]) != string::npos)
        count--;

      left++;
      right++;
      res = max(res, count);
    }

    return res;
  }
};

int main()
{
  Solution s;
  string str = "abciiidef";
  int k = 3;
  cout << s.maxVowels(str, k) << endl;
  return 0;
}