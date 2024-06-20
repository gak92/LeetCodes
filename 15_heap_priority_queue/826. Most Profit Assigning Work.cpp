/*
https://leetcode.com/problems/most-profit-assigning-work/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
  {
    int m = worker.size();
    int n = difficulty.size();

    priority_queue<pair<int, int>> pq; // max heap
    for (int i = 0; i < n; i++)
      pq.push({profit[i], difficulty[i]});

    sort(worker.begin(), worker.end(), greater<int>()); // sort in descending order

    int totalProfit = 0;
    for (int i = 0; i < m; i++)
    {
      while (!pq.empty() && worker[i] < pq.top().second)
        pq.pop();

      if (!pq.empty() && worker[i] >= pq.top().second)
      {
        totalProfit += pq.top().first;
        // pq.pop();
      }
    }

    return totalProfit;
  }
};

int main()
{
  Solution s;
  vector<int> difficulty = {2, 4, 6, 8, 10};
  vector<int> profit = {10, 20, 30, 40, 50};
  vector<int> worker = {4, 5, 6, 7};
  cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;

  return 0;
}