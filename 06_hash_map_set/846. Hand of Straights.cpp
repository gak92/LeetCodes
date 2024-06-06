/*
https://leetcode.com/problems/hand-of-straights/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();

    if (n % groupSize != 0)
      return false;

    map<int, int> mp;
    for (int &num : hand)
    {
      mp[num]++;
    }

    while (!mp.empty())
    {
      int curr = mp.begin()->first;

      for (int i = 0; i < groupSize; i++)
      {
        if (mp[curr + i] == 0)
          return false;

        mp[curr + i]--;
        if (mp[curr + i] < 1)
          mp.erase(curr + i);
      }
    }

    return true;
  }
};

int main()
{
  Solution s;

  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int groupSize = 3;

  cout << s.isNStraightHand(hand, groupSize) << endl;

  return 0;
}