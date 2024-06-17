/*
https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 01 - Brute Force (Time Limit Exceed)
/*

class Solution {
public:
    bool judgeSquareSum(int c) {

        for(long a=0; a*a<=c; a++)
        {
            for(long b=0; b*b<=c; b++)
            {
                if(a*a + b*b == c)
                    return true;
            }
        }

        return false;
    }
};

*/

// Solution # 02- Slight improvement in above approach

class Solution
{
public:
  bool judgeSquareSum(int c)
  {

    for (long a = 0; a * a <= c; a++)
    {
      double b = sqrt(c - a * a);
      if (b == int(b))
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

  return 0;
}