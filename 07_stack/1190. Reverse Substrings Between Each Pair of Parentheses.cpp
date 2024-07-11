/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseParentheses(string s)
  {
    stack<int> st;
    string res;

    for (char &ch : s)
    {
      if (ch == '(')
        st.push(res.length());
      else if (ch == ')')
      {
        int l = st.top();
        st.pop();
        reverse(begin(res) + l, end(res));
      }
      else
        res.push_back(ch);
    }

    return res;
  }
};

int main()
{
  Solution s;
  cout << s.reverseParentheses("(abcd)") << endl;

  return 0;
}