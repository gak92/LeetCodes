/*
https://leetcode.com/problems/contains-duplicate/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_set<int> uniq;

    for (auto &num : nums)
    {
      if (uniq.find(num) != uniq.end())
        return true;

      uniq.insert(num);
    }

    return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.containsDuplicate(nums) << endl;
  return 0;
}