/*
https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"


Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
  string reverseVowels(string s)
  {
    int start = 0;
    int end = s.size() - 1;
    string vowels = "aeiouAEIOU";

    while (start < end)
    {
      while (start < end && vowels.find(s[start]) == string::npos)
      {
        start++;
      }
      while (start < end && vowels.find(s[end]) == string::npos)
      {
        end--;
      }
      swap(s[start], s[end]);
      start++;
      end--;
    }

    return s;
  }
};

int main()
{
  Solution s;
  string str = "hello";
  cout << s.reverseVowels(str) << endl;
}