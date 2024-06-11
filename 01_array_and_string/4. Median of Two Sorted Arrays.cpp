/*
https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size();
    int n = nums2.size();

    int i = 0;
    int j = 0;
    int k = 0;
    int size = m + n;

    vector<int> temp(size);

    while (i < m && j < n)
    {
      if (nums1[i] < nums2[j])
        temp[k++] = nums1[i++];
      else
        temp[k++] = nums2[j++];
    }

    while (i < m)
    {
      temp[k++] = nums1[i++];
    }

    while (j < n)
    {
      temp[k++] = nums2[j++];
    }

    if (size % 2 == 1) // odd
      return temp[size / 2];

    return (temp[size / 2] + temp[size / 2 - 1]) / 2.0;
  }
};

int main()
{
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  Solution s;
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
}