/*
https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using recursion

class Solution
{
private:
  int findWinnerIdx(int n, int k)
  {
    if (n == 1)
      return 0;

    int idx = findWinnerIdx(n - 1, k);
    idx = (idx + k) % n;

    return idx;
  }

public:
  int findTheWinner(int n, int k)
  {

    int resultIdx = findWinnerIdx(n, k);

    return resultIdx + 1;
  }
};

int main()
{
  Solution s;
  cout << s.findTheWinner(5, 2) << endl;
  cout << s.findTheWinner(6, 5) << endl;
  cout << s.findTheWinner(10, 17) << endl;

  return 0;
}