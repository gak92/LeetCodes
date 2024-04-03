/*
https://leetcode.com/problems/build-array-from-permutation/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> buildArray(vector<int> &nums)
  {
    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
      res[i] = nums[nums[i]];
    }

    return res;
  }
};

int main()
{
  vector<int> nums = {0, 2, 1, 5, 3, 4};
  Solution s;
  vector<int> res = s.buildArray(nums);

  return 0;
}