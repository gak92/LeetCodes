/*
https://leetcode.com/problems/daily-temperatures/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> res(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
      int currDay = i;
      int currTemp = temperatures[i];

      while (!st.empty() && currTemp > st.top().second)
      {
        int prevDay = st.top().first;
        res[prevDay] = currDay - prevDay;
        st.pop();
      }

      st.push({currDay, currTemp});
    }

    return res;
  }
};

int main()
{
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution s;
  vector<int> res = s.dailyTemperatures(temperatures);
  cout << "The number of days to wait for warmer temperature: ";
  for (auto d : res)
  {
    cout << d << " ";
  }

  return 0;
}