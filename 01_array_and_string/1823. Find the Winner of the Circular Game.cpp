/*
https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(n^2) solution

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    vector<int> arr;

    for (int i = 1; i <= n; i++)
    {
      arr.push_back(i);
    }

    int i = 0; // start from first element

    while (arr.size() > 1)
    {
      int idx = (i + k - 1) % arr.size();

      arr.erase(arr.begin() + idx);
      i = idx;
    }

    return arr[0];
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