/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0;
    int r = 1;

    while (r < n)
    {
      if (nums[r] != nums[l])
      {
        l++;
        nums[l] = nums[r];
      }
      r++;
    }

    return l + 1;
  }
};

/*

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;

        for(int right=1; right<nums.size(); right++)
        {
            if(nums[right] != nums[right-1])
            {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};


*/

int main()
{
  Solution s;
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << s.removeDuplicates(nums) << endl;
  return 0;
}