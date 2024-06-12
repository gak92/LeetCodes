/*
https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2024-06-12
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    int i = 0;     // 0
    int j = 0;     // 1
    int k = n - 1; // 2

    while (j <= k)
    {
      if (nums[j] == 2)
      {
        swap(nums[j], nums[k]);
        k--;
      }
      else if (nums[j] == 0)
      {
        swap(nums[j], nums[i]);
        i++;
        j++;
      }
      else
      {
        j++;
      }
    }
  }
};

int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution s;
  s.sortColors(nums);

  for (auto i : nums)
    cout << i << " ";
  cout << endl;

  return 0;
}