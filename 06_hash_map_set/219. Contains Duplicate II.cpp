/*
https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int n = nums.size();
    int i = 0;
    int j = 0;
    unordered_set<int> st;

    while (j < n)
    {
      if ((j - i) > k)
      {
        st.erase(nums[i]);
        i++;
      }

      if (st.find(nums[j]) != st.end())
      {
        return true;
      }

      st.insert(nums[j]);
      j++;
    }

    return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.containsNearbyDuplicate(nums, 3) << endl;
  return 0;
}