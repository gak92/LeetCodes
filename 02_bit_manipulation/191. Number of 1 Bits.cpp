/*
https://leetcode.com/problems/number-of-1-bits/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 01 - Right shift the number and check if it is 1 by &(anding) with 1
class Solution
{
public:
  int hammingWeight(int n)
  {
    int count = 0;

    for (int i = 31; i >= 0; i--)
    {
      if (((n >> i) & 1) == 1)
        count++;
    }

    return count;
  }
};

int main()
{
  return 0;
}