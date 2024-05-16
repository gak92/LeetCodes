/*
https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++)
    {
      if (res.empty() || intervals[i][0] > res.back()[1])
      { // if first interval or interval start > last interval end
        res.push_back(intervals[i]);
      }
      else
      { // update last interval end to whichever is max from current and last interval end
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      }
    }

    return res;
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> res = obj.merge(intervals);

  for (auto i : res)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}