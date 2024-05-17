/*
https://leetcode.com/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;

        while(i < intervals.size())
        {
            if(intervals[i][1] < newInterval[0]) {
                i++;
            }
            else if(intervals[i][0] > newInterval[1]) {
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
            }
        }

        intervals.push_back(newInterval);
        return intervals;

    }
};

*/

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    int i = 0;
    int n = intervals.size();
    vector<vector<int>> res;

    while (i < n)
    {
      if (intervals[i][1] < newInterval[0])
      {
        res.push_back(intervals[i]);
      }
      else if (intervals[i][0] > newInterval[1])
      {
        break;
      }
      else
      {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
      }
      i++;
    }

    res.push_back(newInterval);
    while (i < n)
    {
      res.push_back(intervals[i]);
      i++;
    }

    return res;
  }
};

int main()
{
  return 0;
}