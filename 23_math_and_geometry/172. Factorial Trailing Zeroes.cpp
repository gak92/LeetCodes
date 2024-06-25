/*
https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int trailingZeroes(int n)
  {
    int numberOfFives = 0;

    while (n >= 5)
    {
      numberOfFives += n / 5;
      n = n / 5;
    }

    return numberOfFives;
  }
};

int main()
{
  Solution s;
  cout << s.trailingZeroes(3) << endl;
  cout << s.trailingZeroes(5) << endl;
  cout << s.trailingZeroes(10) << endl;
  cout << s.trailingZeroes(30) << endl;
  cout << s.trailingZeroes(100) << endl;
  cout << s.trailingZeroes(1000) << endl;
  cout << s.trailingZeroes(10000) << endl;
  cout << s.trailingZeroes(100000) << endl;
  cout << s.trailingZeroes(1000000) << endl;
  cout << s.trailingZeroes(10000000) << endl;
  cout << s.trailingZeroes(100000000) << endl;
  cout << s.trailingZeroes(1000000000) << endl;
  cout << s.trailingZeroes(10000000000) << endl;
  cout << s.trailingZeroes(100000000000) << endl;
  cout << s.trailingZeroes(1000000000000) << endl;
  cout << s.trailingZeroes(10000000000000) << endl;
  cout << s.trailingZeroes(100000000000000) << endl;
  cout << s.trailingZeroes(1000000000000000) << endl;
  cout << s.trailingZeroes(10000000000000000) << endl;
  cout << s.trailingZeroes(100000000000000000) << endl;
  cout << s.trailingZeroes(1000000000000000000) << endl;
  cout << s.trailingZeroes(10000000000000000000) << endl;
  cout << s.trailingZeroes(100000000000000000000) << endl;
  cout << s.trailingZeroes(1000000000000000000000) << endl;
  cout << s.trailingZeroes(10000000000000000000000) << endl;
  cout << s.trailingZeroes(100000000000000000000000) << endl;
  cout << s.trailingZeroes(1000000000000000000000000) << endl;
  cout << s.trailingZeroes(10000000000000000000000000) << endl;
  cout << s.trailingZeroes(100000000000000000000000000) << endl;

  return 0;
}