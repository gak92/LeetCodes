/*
https://leetcode.com/problems/valid-parentheses/description/
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    unordered_map<char, char> brackets = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}};

    for (int i = 0; i < s.size(); i++)
    {
      // if opening bracket then push into stack
      if (brackets.find(s[i]) != brackets.end())
        st.push(s[i]);
      else
      {
        if (st.empty())
          return false;
        char ch = st.top();
        st.pop();
        if (brackets[ch] != s[i])
          return false;
      }
    }

    return st.empty();
  }
};

int main()
{
  string s = "()";
  Solution sol;
  cout << sol.isValid(s) << endl;
  return 0;
}