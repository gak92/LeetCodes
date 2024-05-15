/*
https://leetcode.com/problems/two-sum/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++)
        {
            int remaining = target - nums[i];       // get the difference

            if(mp.find(remaining) != mp.end()) {    // if present in map
                return {i, mp[remaining]};          // return the index of both
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

*/

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++)
    {
      int diff = target - nums[i];
      if (umap.count(diff))
      {
        return {umap[diff], i};
      }
      umap[nums[i]] = i;
    }

    return {};
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = s.twoSum(nums, target);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}