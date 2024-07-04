/*
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02 - Using partial sort
/*

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(nums.size() <= 4)
            return 0;

        partial_sort(nums.begin(), nums.begin()+4, nums.end());

        nth_element(nums.begin()+4, nums.begin()+(n-4), nums.end());

        sort(nums.begin()+(n-4), nums.end());

        int res = INT_MAX;

        for(int l=0; l<4; l++)
        {
            int r = n - 4 + l;
            res = min(res, nums[r] - nums[l]);
        }

        return res;
    }
};

*/

// Solution # 01
class Solution
{
public:
  int minDifference(vector<int> &nums)
  {
    if (nums.size() <= 4)
      return 0;

    sort(nums.begin(), nums.end());
    int res = INT_MAX;

    for (int l = 0; l < 4; l++)
    {
      int r = nums.size() - 4 + l;
      res = min(res, nums[r] - nums[l]);
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 5, 0, 10, 14};
  cout << s.minDifference(nums) << endl;

  return 0;
}