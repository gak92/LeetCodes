/*
https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool findKthBit(uint32_t n, int k)
  {
    return 1 << (k - 1) & n;
  }

public:
  uint32_t reverseBits(uint32_t n)
  {
    int res = 0;

    for (int i = 1; i <= 32; i++)
    {
      if (findKthBit(n, i))
      { // if current bit is 1
        res = res | 1 << (32 - i);
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  cout << s.reverseBits(43261596) << endl;

  return 0;
}