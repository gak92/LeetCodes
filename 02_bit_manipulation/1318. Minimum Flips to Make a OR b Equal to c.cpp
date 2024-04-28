/*
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res1 = ((a|b) ^ c);

        // if both are 1 in a and b (a&b)
        int res2 = (a&b);

        int res3 = (res2 & res1);

        return __builtin_popcount(res3) + __builtin_popcount(res1);
    }
};
*/

class Solution
{
public:
  int minFlips(int a, int b, int c)
  {
    int flips = 0;

    while (a != 0 || b != 0 || c != 0)
    {

      if ((c & 1) == 1)
      {
        if ((a & 1) == 0 && (b & 1) == 0)
          flips++;
      }
      else
      {
        if ((a & 1) == 1)
          flips++;
        if ((b & 1) == 1)
          flips++;
      }

      a >>= 1;
      b >>= 1;
      c >>= 1;
    }

    return flips;
  }
};
int main()
{
  return 0;
}