/*
https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int count = 0;
    int maj = NULL;

    for (int i = 0; i < nums.size(); i++)
    {
      if (count == 0)
      {
        count = 1;
        maj = nums[i];
      }
      else if (nums[i] == maj)
      {
        count++;
      }
      else
      {
        count--;
      }
    }

    return maj;
  }
};

/*

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        int maxCount = 0;

        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            cout <<"mp[i]" << mp[nums[i]] << endl;
            if(mp[nums[i]] > maxCount)
                res = nums[i];

            maxCount = max(maxCount, mp[nums[i]]);
        }

        return res;
    }
};
*/

int main()
{
  Solution s;
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  cout << s.majorityElement(nums) << endl;

  return 0;
}