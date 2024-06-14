/*
https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minIncrementForUnique(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int moves = 0;

    for (int i = 1; i < n; i++)
    {
      if (nums[i] <= nums[i - 1])
      {
        moves += (nums[i - 1] - nums[i]) + 1;
        nums[i] = nums[i - 1] + 1;
      }
    }

    return moves;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {3, 2, 1, 2, 1, 7};
  cout << s.minIncrementForUnique(nums) << endl;

  return 0;
}