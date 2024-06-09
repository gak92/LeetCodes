/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
      int mid = l + (r - l) / 2;

      if (nums[mid] > nums[r])
        l = mid + 1;
      else
        r = mid;
    }

    return nums[r];
  }
};

int main()
{
  vector<int> nums = {3, 4, 5, 1, 2};
  Solution s;
  cout << s.findMin(nums) << endl;

  return 0;
}