/*
https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minKBitFlips(vector<int> &nums, int k)
  {
    int n = nums.size();
    int flips = 0;
    int flipCountFromPastFori = 0;
    vector<bool> isFlipped(n, false);

    for (int i = 0; i < n; i++)
    {
      if (i >= k && isFlipped[i - k] == true)
        flipCountFromPastFori--;

      if (flipCountFromPastFori % 2 == nums[i])
      {
        if (i + k > n)
          return -1;

        flipCountFromPastFori++;
        flips++;
        isFlipped[i] = true;
      }
    }

    return flips;
  }
};

int main()
{
  vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
  int k = 3;
  Solution s;
  cout << s.minKBitFlips(nums, k) << endl;

  return 0;
}