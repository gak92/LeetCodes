/*
https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    string res = "";
    stack<string> st;
    string token;
    stringstream ss(path);

    while (getline(ss, token, '/'))
    {
      if (token == "" || token == ".")
        continue;

      if (token != "..")
        st.push(token);
      else if (!st.empty())
        st.pop();
    }

    if (st.empty())
      return "/";

    while (!st.empty())
    {
      res = "/" + st.top() + res;
      st.pop();
    }

    return res;
  }
};

int main()
{
  Solution s;
  string path = "/a/./b/../../c/";
  cout << s.simplifyPath(path) << endl;
  return 0;
}