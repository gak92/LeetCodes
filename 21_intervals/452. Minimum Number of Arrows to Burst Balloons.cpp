/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    int n = points.size();
    sort(points.begin(), points.end());
    vector<int> prev = points[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
      int curr_start = points[i][0];
      int curr_end = points[i][1];

      int prev_start = prev[0];
      int prev_end = prev[1];

      if (curr_start > prev_end)
      { // no overlap
        count++;
        prev = points[i];
      }
      else
      { // overlap
        prev[0] = max(curr_start, prev_start);
        prev[1] = min(curr_end, prev_end);
      }
    }

    return count;
  }
};

int main()
{
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  Solution s;
  cout << s.findMinArrowShots(points) << endl;

  return 0;
}