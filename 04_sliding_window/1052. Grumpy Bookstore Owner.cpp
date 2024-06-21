/*
https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
  {
    int n = customers.size();
    int maxUnsatisfied = 0;
    int currUnsatisfied = 0;

    for (int i = 0; i < minutes; i++)
    {
      if (grumpy[i] == 1) // if grumpy is 1, then customer unsatisfied
        currUnsatisfied += customers[i];
    }
    maxUnsatisfied = currUnsatisfied;

    int i = 0;
    int j = minutes;

    while (j < n)
    {
      if (grumpy[j] == 1)
        currUnsatisfied += customers[j];

      if (grumpy[i] == 1)
        currUnsatisfied -= customers[i];

      maxUnsatisfied = max(maxUnsatisfied, currUnsatisfied);

      i++;
      j++;
    }

    int totalSatisfied = maxUnsatisfied;
    for (int i = 0; i < n; i++)
    {
      if (grumpy[i] == 0)
        totalSatisfied += customers[i];
    }

    return totalSatisfied;
  }
};

int main()
{
  Solution obj;
  vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  int minutes = 3;
  cout << obj.maxSatisfied(customers, grumpy, minutes) << endl;

  return 0;
}