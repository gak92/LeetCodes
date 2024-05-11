/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r)
    {
      int currSum = numbers[l] + numbers[r];

      if (currSum > target)
        r--;
      else if (currSum < target)
        l++;
      else
        break;
    }

    return {l + 1, r + 1};
  }
};

int main()
{
  Solution s;
  vector<int> v = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = s.twoSum(v, target);
  for (auto i : res)
    cout << i << " ";
  return 0;
}