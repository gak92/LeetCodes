/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int k = 2; // allow 2 duplicates
    int l = 1;
    int count = 1;

    for (int r = 1; r < nums.size(); r++)
    {
      if (nums[r] == nums[r - 1])
      {
        if (count < k)
          nums[l++] = nums[r];
        count++;
      }
      else
      {
        count = 1;
        nums[l++] = nums[r];
      }
    }

    return l;
  }
};

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;

        while(r < nums.size())
        {
            int count = 1;
            while ((r+1) < nums.size() && nums[r] == nums[r+1]) {   // count no. of duplicates
                count++;
                r++;
            }

            int mini = min(2, count);
            // cout << "mini: " << mini << endl;

            for(int i=0; i<mini; i++) {    // copy duplicates atmost 2 time
                nums[l] = nums[r];
                l++;
            }
            r++;
        }

        return l;
    }
};
*/

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  Solution sol;
  cout << sol.removeDuplicates(nums) << endl;

  return 0;
}