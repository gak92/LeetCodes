/*
https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  double solve(double x, long n)
  {
    if (n == 0)
      return 1;

    if (n < 0)
      return solve(1 / x, -n);

    if (n % 2 == 0)
      return solve(x * x, n / 2);

    return x * solve(x * x, (n - 1) / 2);
  }

public:
  double myPow(double x, int n)
  {

    return solve(x, (long)n);
  }
};

int main()
{
  Solution s;
  cout << s.myPow(2.00000, 10) << endl;

  return 0;
}