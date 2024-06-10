/*
https://leetcode.com/problems/single-element-in-a-sorted-array/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
      int mid = l + (r - l) / 2;
      bool isEven; // check on right are even element
      if ((r - mid) % 2 == 0)
        isEven = true;
      else
        isEven = false;

      if (nums[mid] == nums[mid + 1])
      {
        if (isEven)
          l = mid + 2;
        else
          r = mid - 1;
      }
      else // nums[mid] != nums[mid+1]
      {
        if (isEven)
          r = mid;
        else
          l = mid + 1;
      }
    }

    return nums[r];
  }
};

int main()
{
  Solution obj;
  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  cout << obj.singleNonDuplicate(nums) << endl;

  return 0;
}