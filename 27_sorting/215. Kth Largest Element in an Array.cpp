/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end(), greater<int>());

    return nums[k - 1];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << s.findKthLargest(nums, k) << endl;

  return 0;
}