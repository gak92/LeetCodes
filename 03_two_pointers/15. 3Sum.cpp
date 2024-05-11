/*
https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<vector<int>> res;

  void twoSum(vector<int> &nums, int target, int i, int j)
  {
    while (i < j)
    {
      int total = nums[i] + nums[j];
      if (total > target)
        j--;
      else if (total < target)
        i++;
      else
      {
        while (i < j && nums[i] == nums[i + 1])
          i++;
        while (i < j && nums[j] == nums[j - 1])
          j--;

        res.push_back({-target, nums[i], nums[j]});
        i++;
        j--;
      }
    }
  }

public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();

    if (n < 3)
      return {};

    // res.clear();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int n1 = nums[i];
      int target = -n1;

      twoSum(nums, target, i + 1, n - 1);
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = s.threeSum(nums);

  for (auto i : res)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}