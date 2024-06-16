/*
https://leetcode.com/problems/patching-array/description/?envType=daily-question&envId=2024-06-16
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minPatches(vector<int> &nums, int n)
  {
    long maxReach = 0;
    int patch = 0;
    int i = 0;

    while (maxReach < n)
    {
      if (i < nums.size() && nums[i] <= maxReach + 1)
      {
        maxReach += nums[i];
        i++;
      }
      else
      {
        maxReach += maxReach + 1;
        patch++;
      }
    }

    return patch;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 3};
  int n = 6;
  cout << s.minPatches(nums, n) << endl;

  return 0;
}