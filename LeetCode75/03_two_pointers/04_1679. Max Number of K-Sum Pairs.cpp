/*
https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxOperations(vector<int> &nums, int k)
  {
    int left = 0;
    int right = nums.size() - 1;
    int count = 0;

    sort(nums.begin(), nums.end());

    while (left < right)
    {
      int total = nums[left] + nums[right];
      if (total == k)
      {
        left++;
        right--;
        count++;
      }
      else if (total > k)
        right--;
      else
        left++;
    }

    return count;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  int k = 5;
  Solution sol;
  cout << sol.maxOperations(nums, k) << endl;
  return 0;
}