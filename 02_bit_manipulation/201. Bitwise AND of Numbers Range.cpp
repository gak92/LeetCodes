/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int rangeBitwiseAnd(int left, int right)
  {
    int shiftCount = 0;

    while (left != right)
    {
      left = left >> 1;
      right = right >> 1;
      shiftCount++;
    }

    return left << shiftCount;
  }
};

int main()
{
  Solution s;
  cout << s.rangeBitwiseAnd(5, 7) << endl;
  cout << s.rangeBitwiseAnd(0, 1) << endl;
  cout << s.rangeBitwiseAnd(0, 2147483647) << endl;

  return 0;
}