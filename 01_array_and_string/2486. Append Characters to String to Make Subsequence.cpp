/*
https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int appendCharacters(string s, string t)
  {
    int i = 0;
    int j = 0;
    int m = s.length();
    int n = t.length();

    while (i < m && j < n)
    {
      if (s[i] == t[j])
        j++;

      i++;
    }

    return n - j;
  }
};

int main()
{
  Solution s;
  cout << s.appendCharacters("abc", "abcbc") << endl;

  return 0;
}