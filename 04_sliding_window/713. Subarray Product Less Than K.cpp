/*
https://leetcode.com/problems/subarray-product-less-than-k/description/
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    int left = 0;
    int product = 1;
    int res = 0;

    for (int right = 0; right < nums.size(); right++)
    {
      product *= nums[right];

      while (left <= right && product >= k)
      {
        product = product / nums[left];
        left++;
      }

      res += (right - left + 1);
    }

    return res;
  }
};

int mainnn()
{
  Solution s;
  vector<int> nums = {10, 5, 2, 6};
  int k = 100;
  cout << s.numSubarrayProductLessThanK(nums, k) << endl;
  return 0;
}