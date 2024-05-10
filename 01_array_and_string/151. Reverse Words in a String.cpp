/*
https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res = "";
        string word = "";

        while(ss >> word) {
            res = word + " " + res;
        }

        return res.substr(0, res.length()-1);

    }
};

*/

class Solution
{
public:
  string reverseWords(string s)
  {
    int i = 0;
    int n = s.length();
    int l = 0;
    int r = 0;

    reverse(s.begin(), s.end());

    while (i < n)
    {
      while (i < n && s[i] != ' ')
      {
        s[r] = s[i];
        i++;
        r++;
      }

      if (l < r)
      {
        reverse(s.begin() + l, s.begin() + r);
        s[r] = ' ';
        r++;
        l = r;
      }
      i++;
    }

    s = s.substr(0, r - 1);
    return s;
  }
};

int main()
{
  string str = "the sky is blue";
  Solution s;
  cout << s.reverseWords(str) << endl;

  return 0;
}