/*
https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int res = 0;

    for (int k = 0; k <= 31; k++)
    {
      int countZeroes = 0;
      int countOnes = 0;
      int temp = (1 << k);

      for (auto &num : nums)
      {
        if ((num & temp) == 0)
          countZeroes++;
        else
          countOnes++;
      }

      if (countOnes % 3 == 1)
        res = res | temp;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 2, 3, 2};
  cout << s.singleNumber(nums) << endl;

  return 0;
}