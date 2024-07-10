/*
https://leetcode.com/problems/crawler-log-folder/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    stack<string> st;

    for (auto &log : logs)
    {
      if (log == "../")
      {
        if (!st.empty())
          st.pop();
      }
      else if (log != "./")
      {
        st.push(log);
      }
    }

    return st.size();
  }
};

int main()
{
  Solution s;
  vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  cout << s.minOperations(logs) << endl;

  return 0;
}