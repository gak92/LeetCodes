/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02
/*
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        while(right > left)
        {
            right = right & (right - 1);
        }

        return right;
    }
};
*/
/*
    n & (n-1) use cases:

    1- clear the right most bit
    e.g: 5      1 0 1   (5)
                1 0 0   (4)
                ------   &
                1 0 0   (unset the right most set bit)

    2- calculate the number of set bits
    e.g: 5      1 0 1   (5)
                1 0 0   (4)
                ------  &
                1 0 0   (4)

    again       1 0 0   (4)
                0 1 1   (3)
                ------   &
                0 0 0   (0)

    I did it 2 times, so number of set bits is 2.

    3- Check power of 2
        n > 0 && { n & (n-1) == 0}
*/

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