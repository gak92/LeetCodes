/*

https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Approach : We can use stack to reverse the words in string and then join them with ' '. We can also use 2 pointer approach to reverse the words in string.
// Approach : We can use STL to reverse the words in string and then join them with ' '.

class Solution
{
public:
  string reverseWords(string s)
  {
    string res = "";
    int i = 0;
    int n = s.length();

    while (i < n)
    {
      while (i < n && s[i] == ' ') // getting first non space character
        i++;
      if (i >= n)
        break;
      cout << " i ---> " << i << endl;

      int j = i + 1;
      while (j < n && s[j] != ' ') // getting first space after word
        j++;
      cout << " j ---> " << j << endl;

      string word = s.substr(i, j - i); // extract word and add into result
      cout << " word ---> " << word << endl;

      if (res.length() == 0)
        res = word;
      else
        res = word + " " + res;
      cout << "reverse string ---> " << res << endl;

      i = j + 1;
      cout << "updated i ---> " << i << endl;
      cout << "--------------------------" << endl;
    }

    return res;
  }
};
int main()
{
  string s = "the sky is blue";
  Solution obj;
  cout << obj.reverseWords(s) << endl;
  return 0;
}