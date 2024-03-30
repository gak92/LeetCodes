/*
https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> v1;
    vector<int> v2;

    for (const auto &num : set1)
    {
      if (set2.find(num) == set2.end())
        v1.push_back(num);
    }

    for (const auto &num : set2)
    {
      if (set1.find(num) == set1.end())
        v2.push_back(num);
    }

    return {v1, v2};
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {1, 2, 3, 4, 5, 6};
  vector<vector<int>> res = s.findDifference(nums1, nums2);
  for (const auto &v : res)
  {
    for (const auto &num : v)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}