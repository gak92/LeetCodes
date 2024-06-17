/*
https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool judgeSquareSum(int c)
  {

    long left = 0;
    long right = sqrt(c);

    while (left <= right)
    {
      long total = left * left + right * right;

      if (total < c)
        left++;
      else if (total > c)
        right--;
      else
        return true;
    }

    return false;
  }
};

int main()
{
  Solution s;
  cout << s.judgeSquareSum(5) << endl;
  cout << s.judgeSquareSum(3) << endl;
  cout << s.judgeSquareSum(4) << endl;
  cout << s.judgeSquareSum(2) << endl;
  cout << s.judgeSquareSum(1) << endl;
  cout << s.judgeSquareSum(0) << endl;
  cout << s.judgeSquareSum(1000000000) << endl;

  return 0;
}