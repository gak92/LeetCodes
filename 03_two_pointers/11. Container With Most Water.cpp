/*
https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r)
        {
            int area = (r - l) * min(height[l], height[r]);
            res = max(res, area);

            if(height[l] < height[r])
                l++;
            else
                r--;
        }

        return res;
    }
};
*/
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