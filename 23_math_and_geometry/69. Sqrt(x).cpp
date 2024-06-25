/*
https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x == 0 || x == 1)
      return x;

    int l = 0;
    int r = x;
    int res = 0;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if ((long)mid * mid > x)
        r = mid - 1;
      else if (mid * mid < x)
      {
        l = mid + 1;
        res = mid;
      }
      else
        return mid;
    }

    return res;
  }
};

int main()
{
  Solution s;
  cout << s.mySqrt(8) << endl;

  return 0;
}