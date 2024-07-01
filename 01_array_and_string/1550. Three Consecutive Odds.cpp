/*
https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      if (arr[i] % 2 == 1)
      {
        count++;
        if (count == 3)
          break;
      }
      else
        count = 0;
    }

    if (count == 3)
      return true;

    return false;
  }
};

int main()
{
  Solution s;
  vector<int> arr = {2, 6, 4, 1};
  cout << s.threeConsecutiveOOdds(arr) << endl;

  return 0;
}