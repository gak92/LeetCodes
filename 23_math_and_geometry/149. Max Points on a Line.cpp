/*
https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    int n = points.size();
    if (n == 1)
      return 1;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int count = 2;
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];

        for (int k = 0; k < n; k++)
        {
          if (k != i && k != j)
          {
            int dx_ = points[k][0] - points[i][0];
            int dy_ = points[k][1] - points[i][1];

            if (dx * dy_ == dy * dx_)
              count++;
          }
        }

        res = max(res, count);
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  cout << s.maxPoints(points) << endl;

  return 0;
}