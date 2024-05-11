/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.length();
    int l = 0;
    int r = 0;
    int maxLen = 0;
    unordered_set<char> set;

    while (r < n)
    {
      while (set.find(s[r]) != set.end())
      { // check if character in set
        set.erase(s[l]);
        l++;
      }

      set.insert(s[r]);
      maxLen = max(maxLen, r - l + 1);
      r++;
    }

    return maxLen;
  }
};

/*
s = "abcabcbb"
     l
     r
*/

int main()
{
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;

  return 0;
}