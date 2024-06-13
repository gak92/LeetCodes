/*
https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 01- (using maxheap, vector)
class Solution
{
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
  {
    int n = profits.size();
    vector<pair<int, int>> projects;

    for (int i = 0; i < n; i++)
    {
      projects.push_back({profits[i], capital[i]});
    }

    // sort on the basis of capital
    sort(projects.begin(), projects.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    // max heap (priority queue)
    priority_queue<int> pq;
    int i = 0;

    while (k)
    {
      while (i < n && projects[i].second <= w)
      {
        pq.push(projects[i].first);
        i++;
      }

      if (!pq.empty())
      {
        w += pq.top();
        pq.pop();
      }

      k--;
    }

    return w;
  }
};

int main()
{
  Solution obj;
  vector<int> profits = {1, 2, 3};
  vector<int> capital = {0, 1, 1};
  int k = 2;
  int w = 0;

  cout << obj.findMaximizedCapital(k, w, profits, capital) << endl;

  return 0;
}