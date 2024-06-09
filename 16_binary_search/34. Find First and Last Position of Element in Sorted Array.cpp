/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int findLeftMost(vector<int> &nums, int target, int n)
  {
    int left = 0;
    int right = n - 1;
    int leftMost = -1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      if (target == nums[mid])
      {
        leftMost = mid;
        right = mid - 1;
      }
      else if (target > nums[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }

    return leftMost;
  }

  int findRightMost(vector<int> &nums, int target, int n)
  {
    int left = 0;
    int right = n - 1;
    int rightMost = -1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      if (target == nums[mid])
      {
        rightMost = mid;
        left = mid + 1;
      }
      else if (target > nums[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }

    return rightMost;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int n = nums.size();

    int leftMost = findLeftMost(nums, target, n);
    int rightMost = findRightMost(nums, target, n);

    return {leftMost, rightMost};
  }
};

int main()
{
  Solution s;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;

  vector<int> result = s.searchRange(nums, target);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}