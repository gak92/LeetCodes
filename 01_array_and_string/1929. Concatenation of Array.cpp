/*
https://leetcode.com/problems/concatenation-of-array/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getConcatenation(vector<int> &nums)
  {
    int size = nums.size();
    vector<int> res(2 * size);

    for (int i = 0; i < size; i++)
    {
      res[i] = nums[i];
      res[i + size] = nums[i];
    }

    return res;
  }
};

int main()
{
  vector<int> nums = {1, 2, 1};
  Solution s;
  vector<int> res = s.getConcatenation(nums);
  return 0;
}