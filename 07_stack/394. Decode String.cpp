/*
https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string repeat(string substr, int times)
  {
    string res = "";
    for (int i = 0; i < times; i++)
    {
      res += substr;
    }
    return res;
  }

  string decodeString(string s)
  {
    stack<char> st;

    for (auto &c : s)
    {
      if (c != ']')
      {
        st.push(c);
      }
      else
      {
        string sub = "";
        while (st.top() != '[')
        {
          sub = st.top() + sub;
          st.pop();
        }
        st.pop(); // pop '['

        string digit = "";
        while (!st.empty() && isdigit(st.top()))
        {
          digit = st.top() + digit;
          st.pop();
        }
        int times = stoi(digit);
        string substr = repeat(sub, times);

        for (int i = 0; i < substr.size(); i++)
        {
          st.push(substr[i]);
        }
      }
    } // end for loop

    string res = "";
    while (!st.empty())
    {
      res = st.top() + res;
      st.pop();
    }

    return res;
  }
};

int main()
{
  string s = "3[a]2[bc]";
  Solution sol;
  cout << sol.decodeString(s) << endl;
  return 0;
}