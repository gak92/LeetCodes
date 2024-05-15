/*
https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    unordered_set<int> st;

    for (auto &num : nums)
    {
      st.insert(num);
    }

    int longest = 0;

    for (auto &num : nums)
    {
      // if num - 1 not in set, start a sequence from there
      if (st.find(num - 1) == st.end())
      {
        int length = 1;
        while (st.find(num + length) != st.end())
        {
          length++;
        }

        longest = max(longest, length);
      }
    }

    return longest;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << s.longestConsecutive(nums) << endl;
  return 0;
}