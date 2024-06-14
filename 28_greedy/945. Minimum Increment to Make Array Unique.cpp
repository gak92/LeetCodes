/*
https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/?envType=daily-question&envId=2024-06-14
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minIncrementForUnique(vector<int> &nums)
  {
    int n = nums.size();
    int maxElement = *max_element(nums.begin(), nums.end());
    vector<int> count(n + maxElement, 0);

    for (auto &num : nums)
    {
      count[num]++;
    }

    int moves = 0;

    for (int i = 0; i < n + maxElement; i++)
    {
      if (count[i] <= 1)
        continue;

      int extra = count[i] - 1;
      count[i + 1] += extra;
      moves += extra;
      count[i] = 1;
    }

    return moves;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {3, 2, 1, 2, 1, 7};
  cout << s.minIncrementForUnique(nums) << endl;

  return 0;
}