/*
https://leetcode.com/problems/total-cost-to-hire-k-workers/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long totalCost(vector<int> &costs, int k, int candidates)
  {
    long long res;
    int n = costs.size();
    priority_queue<int, vector<int>, greater<int>> pq1, pq2; // min heap
    int hired = 0;
    int i = 0, j = n - 1;

    while (hired < k)
    {
      while (pq1.size() < candidates && i <= j)
      {
        pq1.push(costs[i]);
        i++;
      }

      while (pq2.size() < candidates && j >= i)
      {
        pq2.push(costs[j]);
        j--;
      }

      int min_pq1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
      int min_pq2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

      if (min_pq1 <= min_pq2)
      {
        res += min_pq1;
        pq1.pop();
      }
      else
      {
        res += min_pq2;
        pq2.pop();
      }
      cout << "res: " << res;

      hired++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> costs = {10, 20, 5};
  int k = 2;
  int candidates = 2;
  cout << s.totalCost(costs, k, candidates);

  return 0;
}