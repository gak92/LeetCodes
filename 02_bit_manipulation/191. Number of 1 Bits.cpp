/*
https://leetcode.com/problems/number-of-1-bits/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02 - By unsetting(0) the rightmost set bit(1)
/*

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n > 0)
        {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

*/

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