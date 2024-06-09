/*
https://leetcode.com/problems/find-peak-element/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int left = 0;
    int size = nums.size() - 1;
    int right = nums.size() - 1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      if (mid < size && nums[mid] < nums[mid + 1]) // check right neighbor
        left = mid + 1;
      else if (mid > 0 && nums[mid] < nums[mid - 1]) // check left neighbor
        right = mid - 1;
      else
        return mid;
    }

    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.findPeakElement(nums) << endl;
  return 0;
}