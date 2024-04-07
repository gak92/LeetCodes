/*
https://leetcode.com/problems/subarray-sum-equals-k/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int currSum = 0;
    int res = 0;
    unordered_map<int, int> preSum;
    preSum[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
      currSum += nums[i];
      if (preSum.find(currSum - k) != preSum.end())
        res += preSum[currSum - k];

      preSum[currSum]++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 1};
  int k = 2;
  cout << s.subarraySum(nums, k) << endl;
  return 0;
}