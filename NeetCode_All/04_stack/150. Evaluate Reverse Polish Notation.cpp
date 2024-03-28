/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;
    int val1, val2;

    for (auto c : tokens)
    {
      if (c == "+")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(val2 + val1);
      }
      else if (c == "-")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(val1 - val2);
      }
      else if (c == "*")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(val2 * val1);
      }
      else if (c == "/")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(ceil(val1 / val2));
      }
      else
      {
        st.push(stoi(c));
      }
    }

    return st.top();
  }
};

int main()
{
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  Solution sol;
  cout << sol.evalRPN(tokens) << endl;
  return 0;
}