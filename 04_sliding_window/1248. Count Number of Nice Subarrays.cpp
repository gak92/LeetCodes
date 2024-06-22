/*
https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    int oddCount = 0;
    int prevCount = 0;
    int res = 0;
    int i = 0;
    int j = 0;

    while (j < n)
    {
      if (nums[j] % 2 != 0)
      { // ODD
        oddCount++;
        prevCount = 0;
      }

      while (oddCount == k)
      {
        prevCount++;

        if (i < n && nums[i] % 2 == 1) // ODD
          oddCount--;
        i++;
      }

      res += prevCount;
      j++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << s.numberOfSubarrays(nums, k) << endl;

  return 0;
}