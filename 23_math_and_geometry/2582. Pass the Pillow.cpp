/*
https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-05
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int passThePillow(int n, int time)
  {
    int idx = 1; // position of the pillow
    int dir = 1; // Left to Right

    while (time > 0)
    {
      if (idx + dir >= 1 && idx + dir <= n)
      {
        idx += dir;
        time--;
      }
      else
      {
        dir *= -1;
      }
    }

    return idx;
  }
};

int main()
{
  Solution s;
  cout << s.passThePillow(5, 3) << endl;

  return 0;
}