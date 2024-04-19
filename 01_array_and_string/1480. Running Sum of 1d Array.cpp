/*
https://leetcode.com/problems/running-sum-of-1d-array/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02 - Use the same array to store the sum of each element

// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {

//         for(int i=1; i<nums.size(); i++) {
//             nums[i] += nums[i-1];
//         }

//         return nums;
//     }
// };

// Solution # 01 - Using extra space to store the sum of each element in a new array
class Solution
{
public:
  vector<int> runningSum(vector<int> &nums)
  {
    vector<int> res;
    int total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      total += nums[i];
      res.push_back(total);
    }

    return res;
  }
};
int main()
{
  vector<int> nums = {1, 2, 3, 4};
  Solution s;
  vector<int> res = s.runningSum(nums);

  return 0;
}