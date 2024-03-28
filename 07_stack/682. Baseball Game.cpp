/*
https://leetcode.com/problems/baseball-game/description/
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int calPoints(vector<string> &operations)
  {
    stack<int> st;
    int size = operations.size();

    for (int i = 0; i < size; i++)
    {
      if (operations[i] == "+")
      {
        int temp1 = st.top();
        st.pop();
        int temp2 = st.top();
        st.push(temp1);
        st.push(temp1 + temp2);
      }
      else if (operations[i] == "C")
        st.pop();
      else if (operations[i] == "D")
        st.push(2 * st.top());
      else
        st.push(stoi(operations[i]));
    }

    int total = 0;
    while (!st.empty())
    {
      total += st.top();
      st.pop();
    }

    return total;
  }
};

int main()
{
  vector<string> operations = {"5", "2", "C", "D", "+"};
  Solution sol;
  cout << sol.calPoints(operations) << endl;
  return 0;
}