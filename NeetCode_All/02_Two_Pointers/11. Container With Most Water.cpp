/*
https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int left = 0;
    int right = height.size() - 1;
    int maximumArea = -1;

    while (left < right)
    {
      int length = min(height[left], height[right]);
      int width = right - left;

      int currArea = length * width;
      maximumArea = max(maximumArea, currArea);

      if (height[left] < height[right])
        left++;
      else
        right--;
    }

    return maximumArea;
  }
};

int main()
{
  Solution a;
  vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << a.maxArea(input) << endl;
  return 0;
}