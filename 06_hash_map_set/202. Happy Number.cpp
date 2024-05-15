/*
https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int sumOfSquare(int n)
  {
    int res = 0;

    while (n)
    {
      int digit = n % 10;
      res += pow(digit, 2);
      n = n / 10;
    }

    return res;
  }

public:
  bool isHappy(int n)
  {
    unordered_set<int> visited;

    while (visited.find(n) == visited.end()) // if n not in set
    {
      visited.insert(n);
      if (n == 1)
        return true;

      n = sumOfSquare(n);
    }

    return false;
  }
};

int main()
{
  Solution s;
  cout << s.isHappy(19) << endl;
  return 0;
}