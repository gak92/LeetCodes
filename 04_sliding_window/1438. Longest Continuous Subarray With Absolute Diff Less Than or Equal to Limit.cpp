/*
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/submissions/1297647711/?envType=daily-question&envId=2024-06-23
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  typedef pair<int, int> P;

public:
  int longestSubarray(vector<int> &nums, int limit)
  {
    int n = nums.size();
    priority_queue<P, vector<P>> maxheap;             // max heap
    priority_queue<P, vector<P>, greater<P>> minheap; // min heap

    int i = 0;
    int j = 0;
    int maxLength = 0;

    while (j < n)
    {
      maxheap.push({nums[j], j});
      minheap.push({nums[j], j});

      // shrink window
      while (maxheap.top().first - minheap.top().first > limit)
      {
        i = min(maxheap.top().second, minheap.top().second) + 1;

        while (maxheap.top().second < i)
          maxheap.pop();

        while (minheap.top().second < i)
          minheap.pop();
      }

      maxLength = max(maxLength, j - i + 1);
      j++;
    }

    return maxLength;
  }
};

int main()
{
  vector<int> nums = {8, 2, 4, 7};
  int limit = 4;

  Solution s;
  cout << s.longestSubarray(nums, limit) << endl;

  return 0;
}