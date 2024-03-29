/*
https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int leftSum = 0;
    int rightSum;
    int total = 0;

    for (auto num : nums)
      total += num;

    for (int i = 0; i < nums.size(); i++)
    {
      rightSum = total - nums[i] - leftSum;
      if (leftSum == rightSum)
        return i;

      leftSum += nums[i];
    }

    return -1;
  }
};

int main()
{
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  Solution sol;
  cout << "Pivot Index is: " << sol.pivotIndex(nums) << endl;
  return 0;
}