/*
https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/


#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int left = 0;

        for(int right=0; right<nums.size(); right++)
        {
            if(nums[right] != 0 && nums[left] == 0)
                swap(nums[left], nums[right]);

            if(nums[left] != 0)
                left++;
        }
        
        
        // int left = 0;
        // int right = 0;

        // while(right < nums.size())
        // {
        //     if(nums[right] != 0)
        //     {
        //         nums[left] = nums[right];
        //         left++;
        //     }
        //     right++;
        // }
        // right = left;
        // while(right < nums.size())
        // {
        //     nums[right] = 0;
        //     right++;
        // }
    }
};

int main()
{
    vector<int> nums = {0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}