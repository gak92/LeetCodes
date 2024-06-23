/*
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums, int limit)
  {
    int n = nums.size();
    multiset<int> mset;

    int i = 0;
    int j = 0;
    int maxLength = 0;

    while (j < n)
    {
      mset.insert(nums[j]);

      // shrink window
      while (*mset.rbegin() - *mset.begin() > limit)
      {
        mset.erase(mset.find(nums[i]));
        i++;
      }

      maxLength = max(maxLength, j - i + 1);
      j++;
    }

    return maxLength;
  }
};

int main()
{
  vector<int> nums = {8, 2, 4, 7};
  int limit = 4;

  Solution s;
  cout << s.longestSubarray(nums, limit) << endl;

  return 0;
}