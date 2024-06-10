/*
https://leetcode.com/problems/height-checker/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void countingSort(vector<int> &nums)
  {
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    unordered_map<int, int> mp;
    for (auto &num : nums)
      mp[num]++;

    int i = 0;
    for (int num = minVal; num <= maxVal; num++)
    {
      while (mp[num] > 0)
      {
        nums[i] = num;
        i++;
        mp[num]--;
      }
    }
  }

public:
  int heightChecker(vector<int> &heights)
  {
    int n = heights.size();

    vector<int> expected = heights;
    countingSort(expected);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
      if (heights[i] != expected[i])
        res++;
    }

    return res;
  }
};

int main()
{
  Solution obj;
  vector<int> heights = {1, 1, 4, 2, 1, 3};
  cout << obj.heightChecker(heights) << endl;

  return 0;
}