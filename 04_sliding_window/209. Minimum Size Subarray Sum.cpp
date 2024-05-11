/*
https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int n = nums.size();
    int l = 0;
    int r = 0;
    int minLen = INT_MAX;
    int total = 0;

    while (r < n)
    {
      total += nums[r];

      while (total >= target)
      {
        minLen = min(minLen, r - l + 1);
        total -= nums[l];
        l++;
      }
      r++;
    }

    return minLen == INT_MAX ? 0 : minLen;
  }
};

int main()
{
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  Solution s;
  cout << s.minSubArrayLen(target, nums) << endl;

  return 0;
}