/*
https://leetcode.com/problems/non-overlapping-intervals/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int count = 0;
        int i = 0;
        int j = 1;

        while(j < n) {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];

            if(ce <= ns) {  // no overlapping
                i = j;
                j++;
            } else if(ce <= ne)  { // overlapping
                j++;
                count++;
            } else if(ce > ne) {    // overlapping
                i = j;
                j++;
                count++;
            }
        }

        return count;
    }
};
*/

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    int count = 0;
    vector<int> L = intervals[0];
    int i = 1;

    while (i < n)
    {
      int curr_start = intervals[i][0];
      int curr_end = intervals[i][1];

      int last_end = L[1];

      if (curr_start >= last_end)
      { // safe
        L = intervals[i];
      }
      else if (curr_end >= last_end)
      { // overlapping
        count++;
      }
      else if (last_end > curr_end)
      {
        count++;
        L = intervals[i];
      }
      i++;
    }

    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  cout << s.eraseOverlapIntervals(intervals) << endl;
  return 0;
}