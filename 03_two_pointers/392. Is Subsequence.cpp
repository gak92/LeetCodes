/*

https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j])
                i++;
            j++;
        }

        return i == s.length();
    }
};
*/

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {

    int left = 0;
    int right = 0;

    while (left < s.length() && right < t.length())
    {
      if (s[left] == t[right])
      {
        left++;
        right++;
      }
      else
      {
        right++;
      }
    }

    return left == s.length();
  }
};

int main()
{
  Solution s;
  string s1 = "abc";
  string s2 = "ahbgdc";
  cout << s.isSubsequence(s1, s2) << endl;
  return 0;
}