/*
https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int bruteForce(vector<int> &nums)
  {
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
      int currSum = 0;
      for (int j = i; j < nums.size(); j++)
      {
        currSum += nums[j];
        maxSum = max(maxSum, currSum);
      }
    }

    return maxSum;
  }

  int kadanes(vector<int> &nums)
  {
    int maxSum = nums[0];
    int currSum = 0;

    for (auto &num : nums)
    {
      if (currSum < 0)
        currSum = 0;
      currSum += num;

      maxSum = max(maxSum, currSum);
    }

    return maxSum;
  }

public:
  int maxSubArray(vector<int> &nums)
  {

    // brute force O(n^2) (Time Limit Exceed)
    // return bruteForce(nums);

    // Kadane's Algorithm
    return kadanes(nums);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << s.maxSubArray(nums) << endl;
  return 0;
}