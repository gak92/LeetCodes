/*
https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> mp;

    int res = 0;
    int oddCount = 0;
    mp[oddCount] = 1;

    for (int i = 0; i < n; i++)
    {
      oddCount += nums[i] % 2;

      if (mp.count(oddCount - k))
      {
        res += mp[oddCount - k];
      }

      mp[oddCount]++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << s.numberOfSubarrays(nums, k) << endl;

  return 0;
}