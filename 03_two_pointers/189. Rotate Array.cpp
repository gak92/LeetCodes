/*
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void reverseArray(vector<int> &nums, int l, int r)
  {
    int temp;
    while (l < r)
    {
      temp = nums[l];
      nums[l] = nums[r];
      nums[r] = temp;
      l++;
      r--;
    }
  }

public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k = k % n;
    int l = 0;
    int r = n - 1;

    reverseArray(nums, l, r);     // reverse entire array
    reverseArray(nums, l, k - 1); // reverse first k element
    reverseArray(nums, k, r);     // reverse remaining array
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  Solution s;
  s.rotate(nums, k);
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }

  return 0;
}