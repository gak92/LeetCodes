/*
https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestAltitude(vector<int> &gain)
  {
    int currAlt = 0;
    int maxAlt = 0;

    for (int i = 0; i < gain.size(); i++)
    {
      currAlt += gain[i];
      maxAlt = max(maxAlt, currAlt);
    }

    return maxAlt;
  }
};
int main()
{
  vector<int> gain = {-5, 1, 5, 0, -7};
  Solution sol;
  cout << "The highest altitude is: " << sol.largestAltitude(gain) << endl;
  return 0;
}
