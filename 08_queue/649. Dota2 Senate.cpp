/*
https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string predictPartyVictory(string senate)
  {
    queue<int> rad, dir;
    int n = senate.size();

    for (int i = 0; i < n; i++)
    {
      if (senate[i] == 'R')
        rad.push(i);
      else
        dir.push(i);
    }

    while (!rad.empty() && !dir.empty())
    {
      if (rad.front() < dir.front())
        rad.push(n++);
      else
        dir.push(n++);

      rad.pop();
      dir.pop();
    }

    return rad.empty() ? "Dire" : "Radiant";
  }
};

int main()
{
  Solution *obj = new Solution();
  cout << obj->predictPartyVictory("RD") << endl;  // Output: Radiant
  cout << obj->predictPartyVictory("RDD") << endl; // Output: Dire
  return 0;
}