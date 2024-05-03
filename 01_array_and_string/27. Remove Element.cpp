/*
https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeElement(vector<int> &nums, int val)
  {
    int k = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != val)
      {
        swap(nums[i], nums[k]);
        k++;
      }
    }

    return k;
  }
};

/*
     i
     0  1
    [3, 3]
     j

*/

int main()
{
  Solution s;
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  cout << s.removeElement(nums, val) << endl;

  // print nums
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }

  return 0;
}