/*
https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int kadanesMax(vector<int> &nums, int n)
  {
    int currSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < n; i++)
    {
      currSum = max(currSum + nums[i], nums[i]);
      maxSum = max(maxSum, currSum);
    }

    return maxSum;
  }

  int kadanesMin(vector<int> &nums, int n)
  {
    int currSum = nums[0];
    int minSum = nums[0];

    for (int i = 1; i < n; i++)
    {
      currSum = min(currSum + nums[i], nums[i]);
      minSum = min(minSum, currSum);
    }

    return minSum;
  }

public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int n = nums.size();

    int SUM = accumulate(nums.begin(), nums.end(), 0);

    int minSum = kadanesMin(nums, n);
    int maxSum = kadanesMax(nums, n);

    int circularSum = SUM - minSum;

    if (maxSum > 0)
      return max(maxSum, circularSum);

    return maxSum;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, -2, 3, -2};
  cout << s.maxSubarraySumCircular(nums) << endl;
  return 0;
}