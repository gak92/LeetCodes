/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    int m = haystack.length();
    int n = needle.length();

    for (int i = 0; i < m - n + 1; i++) // for haystack
    {
      for (int j = 0; j < n; j++) // for needle
      {
        if (needle[j] != haystack[i + j])
          break;

        if (j == n - 1)
          return i;
      }
    }

    return -1;
  }
};

/*

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

int main()
{
  string haystack = "sadbutsad";
  string needle = "sad";

  Solution s;
  cout << s.strStr(haystack, needle) << endl;

  return 0;
}