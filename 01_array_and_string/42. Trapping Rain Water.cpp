/*
https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 01

class Solution
{
private:
  vector<int> getLeftMaxArray(vector<int> &height, int &n)
  {
    vector<int> leftMax(n);
    leftMax[0] = height[0];

    for (int i = 1; i < n; i++)
    {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    return leftMax;
  }

  vector<int> getRightMaxArray(vector<int> &height, int &n)
  {
    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    return rightMax;
  }

public:
  int trap(vector<int> &height)
  {
    int n = height.size();

    vector<int> leftMax = getLeftMaxArray(height, n);
    vector<int> rightMax = getRightMaxArray(height, n);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
      res += min(leftMax[i], rightMax[i]) - height[i];
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(height) << endl;
  return 0;
}