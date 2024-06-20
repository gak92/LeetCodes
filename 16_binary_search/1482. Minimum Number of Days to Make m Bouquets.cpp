/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int canMakeMBouquets(vector<int> &bloomDay, int midDay, int k)
  {
    int bouquetCount = 0;
    int consecutiveCount = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
      if (bloomDay[i] <= midDay)
        consecutiveCount++;
      else
        consecutiveCount = 0;

      if (consecutiveCount == k)
      {
        bouquetCount++;
        consecutiveCount = 0;
      }
    }

    return bouquetCount;
  }

public:
  int minDays(vector<int> &bloomDay, int m, int k)
  {
    int n = bloomDay.size();
    int startDay = 0;
    int endDay = *max_element(bloomDay.begin(), bloomDay.end());
    int minDays = -1;

    while (startDay <= endDay)
    {
      int midDay = startDay + (endDay - startDay) / 2; // l + (r - l) / 2

      if (canMakeMBouquets(bloomDay, midDay, k) >= m)
      {
        minDays = midDay;
        endDay = midDay - 1;
      }
      else
      {
        startDay = midDay + 1;
      }
    }

    return minDays;
  }
};

int main()
{
  Solution solution;
  vector<int> bloomDay = {1, 10, 3, 10, 2};
  int m = 3;
  int k = 1;

  cout << solution.minDays(bloomDay, m, k) << endl;

  return 0;
}