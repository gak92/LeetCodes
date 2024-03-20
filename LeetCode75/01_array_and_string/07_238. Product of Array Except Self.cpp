/*
https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);

    int prefix = 1;
    for (int i = 0; i < n; i++) // 0,   1,   2,   3     (index)
    {                           // 1,   2,   3,   4     (nums)
      res[i] = prefix;          // 1,   1,   2,   6     (res)
      prefix *= nums[i];        // 1    2,   6,   24    (prefix)
    }

    int postfix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      res[i] *= postfix;
      postfix *= nums[i];
    }

    return res;

    // Solve but take extra space
    // int n = nums.size();
    // vector<int> res(n);
    // vector<int> prefix(n);
    // vector<int> postfix(n);

    // prefix[0] = 1;
    // for(int i=1; i<n; i++)
    // {
    //     prefix[i] = prefix[i-1] * nums[i-1];
    // }
    // postfix[n-1] = 1;
    // for(int i=n-2; i>=0; i--)
    // {
    //     postfix[i] = postfix[i+1] * nums[i+1];
    // }

    // for(int i=0; i<n; i++)
    // {
    //     cout << prefix[i] << ", ";
    // }
    // cout << endl;

    // for(int i=0; i<n; i++)
    // {
    //     cout << postfix[i] << ", ";
    // }
    // cout << endl;

    // for(int i=0; i<n; i++)
    // {
    //     res[i] = prefix[i] * postfix[i];
    // }

    // return res;

    // Time Limit Exceed -- Time Complexity: O(n^2)
    // vector<int> res;
    // int mul;

    // for(int i=0; i<nums.size(); i++)
    // {
    //     mul = 1;
    //     for(int j=0; j<nums.size(); j++)
    //     {
    //         if(i != j)
    //         {
    //             mul *= nums[j];
    //         }
    //     }
    //     res.push_back(mul);
    // }

    // return res;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  Solution obj;
  vector<int> res = obj.productExceptSelf(nums);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << ", ";
  }
  cout << endl;
  return 0;
}