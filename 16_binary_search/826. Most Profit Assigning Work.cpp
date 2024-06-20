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

    vector<pair<int, int>> projects;
    for (int i = 0; i < n; i++)
      projects.push_back({difficulty[i], profit[i]});

    // sort on the basis of difficulty
    sort(projects.begin(), projects.end());

    // pre-processing to find max profit till ith project
    for (int i = 1; i < projects.size(); i++)
      projects[i].second = max(projects[i].second, projects[i - 1].second);

    int totalProfit = 0;

    for (int i = 0; i < m; i++)
    {
      int workerDiffLevel = worker[i];
      int l = 0;
      int r = projects.size() - 1;
      int maxProfit = 0;

      while (l <= r)
      {
        int mid = l + (r - l) / 2;
        if (projects[mid].first <= workerDiffLevel)
        {
          maxProfit = max(maxProfit, projects[mid].second);
          l = mid + 1;
        }
        else
        {
          r = mid - 1;
        }
      }

      totalProfit += maxProfit;
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