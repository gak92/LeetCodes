/*
https://leetcode.com/problems/average-waiting-time/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double averageWaitingTime(vector<vector<int>> &customers)
  {
    int n = customers.size();
    double totalWaitTime = 0;
    int currTime = 0;

    for (auto &vec : customers)
    {
      int arrivalTime = vec[0];
      int cookTime = vec[1];

      if (currTime < arrivalTime)
        currTime = arrivalTime;

      int waitTime = currTime + cookTime - arrivalTime;
      totalWaitTime += waitTime;
      currTime += cookTime;
    }

    return totalWaitTime / n;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
  cout << s.averageWaitingTime(customers) << endl;

  return 0;
}