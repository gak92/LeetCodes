/*
https://leetcode.com/problems/running-sum-of-1d-array/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> runningSum(vector<int> &nums)
  {
    vector<int> res;
    int total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      total += nums[i];
      res.push_back(total);
    }

    return res;
  }
};
int main()
{
  vector<int> nums = {1, 2, 3, 4};
  Solution s;
  vector<int> res = s.runningSum(nums);

  return 0;
}