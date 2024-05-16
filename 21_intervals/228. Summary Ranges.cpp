/*
https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> summaryRanges(vector<int> &nums)
  {
    int n = nums.size();
    vector<string> res;

    for (int i = 0; i < n; i++)
    {
      int start = nums[i];
      while (i + 1 < n && nums[i] + 1 == nums[i + 1])
      {
        i++;
      }

      if (start != nums[i])
      {
        res.push_back(to_string(start) + "->" + to_string(nums[i]));
      }
      else
      {
        res.push_back(to_string(start));
      }
    }

    return res;
  }
};

int main()
{
  Solution obj;
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  vector<string> res = obj.summaryRanges(nums);

  for (auto i : res)
  {
    cout << i << " ";
  }
  return 0;
}