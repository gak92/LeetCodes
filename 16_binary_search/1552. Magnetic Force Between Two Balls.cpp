/*
https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool ballsCanPlace(int force, vector<int> &position, int m)
  {
    int prev = position[0];
    int countBalls = 1;

    for (int i = 1; i < position.size(); i++)
    {
      int curr = position[i];
      if (curr - prev >= force)
      {
        countBalls++;
        prev = curr;
      }

      if (countBalls == m)
        break;
    }

    return countBalls == m;
  }

public:
  int maxDistance(vector<int> &position, int m)
  {
    int n = position.size();
    sort(position.begin(), position.end());

    int minForce = 1;
    int maxForce = position[n - 1] - position[0];

    int maxDistance = 0;

    while (minForce <= maxForce)
    {
      int midForce = minForce + (maxForce - minForce) / 2;
      if (ballsCanPlace(midForce, position, m))
      {
        maxDistance = midForce;
        minForce = midForce + 1;
      }
      else
      {
        maxForce = midForce - 1;
      }
    }

    return maxDistance;
  }
};

int main()
{
  vector<int> position = {1, 2, 3, 4, 7};
  int m = 3;

  Solution obj;
  cout << obj.maxDistance(position, m) << endl;

  return 0;
}