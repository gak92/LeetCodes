/*
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75
*/

/*
    nums = [0, 1, 1, 1, 0, 1, 1, 0, 1]
            l
               r

    num_of_zeros = 1

*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums)
  {

    int left = 0;
    int right = 0;
    int numOfZeroes = 1;
    int maxLen = 0;

    while (right < nums.size())
    {
      if (nums[right] == 0)
        numOfZeroes--;

      while (numOfZeroes < 0)
      {
        if (nums[left] == 0)
          numOfZeroes++;
        left++;
      }

      maxLen = max(maxLen, right - left);
      right++;
    }

    return maxLen;
  }
};

int main()
{
  vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  Solution s;
  cout << s.longestSubarray(nums) << endl;
  return 0;
}
