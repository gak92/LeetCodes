/*

https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int left = 0;
    int right = 0;
    int countZeroes = 0;
    int res = INT_MIN;

    while (right < nums.size())
    {
      if (nums[right] == 0)
      {
        countZeroes++;
      }

      while (countZeroes > k)
      {
        if (nums[left] == 0)
          countZeroes--;
        left++;
      }

      res = max(res, right - left + 1);
      right++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  cout << s.longestOnes(nums, k) << endl;
  return 0;
}