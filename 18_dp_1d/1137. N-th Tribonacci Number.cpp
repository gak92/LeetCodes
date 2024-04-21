/*
https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int tribonacci(int n)
  {
    vector<int> t{0, 1, 1};

    if (n < 3)
      return t[n];

    for (int i = 3; i <= n; i++)
    {
      int total = t[0] + t[1] + t[2];
      t[0] = t[1];
      t[1] = t[2];
      t[2] = total;
    }

    return t[2];
  }
};

int main()
{
  Solution *obj = new Solution();
  cout << obj->tribonacci(25) << endl;

  return 0;
}