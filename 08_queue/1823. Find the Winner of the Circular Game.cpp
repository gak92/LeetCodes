/*
https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using queue solution

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    queue<int> q;
    for (int i = 1; i <= n; i++)
      q.push(i);

    while (q.size() > 1)
    {
      for (int i = 1; i < k; i++)
      {
        q.push(q.front());
        q.pop();
      }
      q.pop();
    }

    return q.front();
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