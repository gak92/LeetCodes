/*
https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeStars(string s)
  {
    stack<char> st;

    for (auto &ch : s)
    {
      if (ch != '*')
        st.push(ch);
      else if (!st.empty())
        st.pop();
    }

    string res = "";
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }

    reverse(res.begin(), res.end());

    return res;
  }
};

int main()
{
  Solution s;
  cout << "Output of the program is : " << s.removeStars("leet**cod*e") << endl; // lecoe
  return 0;
}