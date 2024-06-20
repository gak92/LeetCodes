/*
https://leetcode.com/problems/most-profit-assigning-work/submissions/1292554869/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
  {
    int n = difficulty.size();
    int m = worker.size();

    vector<pair<int, int>> projects;

    for (int i = 0; i < n; i++)
    {
      projects.push_back({difficulty[i], profit[i]});
    }

    sort(projects.begin(), projects.end());
    sort(worker.begin(), worker.end());

    int maxProfit = 0;
    int totalProfit = 0;
    int j = 0;

    for (int i = 0; i < m; i++)
    {
      while (j < n && worker[i] >= projects[j].first)
      {
        maxProfit = max(maxProfit, projects[j].second);
        j++;
      }

      totalProfit += maxProfit;
    }

    return totalProfit;
  }
};

int main()
{
  Solution obj;
  vector<int> difficulty = {2, 4, 6, 8, 10};
  vector<int> profit = {10, 20, 30, 40, 50};
  vector<int> worker = {4, 5, 6, 7};
  cout << obj.maxProfitAssignment(difficulty, profit, worker) << endl;

  return 0;
}
