/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int findPivot(vector<int> &nums, int target, int n)
  {
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

    return r;
  }

  int binarySearch(vector<int> &nums, int target, int l, int r, int n)
  {
    int idx = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (target == nums[mid])
      {
        idx = mid;
        break;
      }
      else if (target > nums[mid])
        l = mid + 1;
      else
        r = mid - 1;
    }

    return idx;
  }

public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();

    int pivotIdx = findPivot(nums, target, n);

    int idx = binarySearch(nums, target, 0, pivotIdx - 1, n);

    if (idx != -1)
      return idx;

    idx = binarySearch(nums, target, pivotIdx, n - 1, n);

    return idx;
  }
};

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  Solution s;
  cout << s.search(nums, target) << endl;

  return 0;
}