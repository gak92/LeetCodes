/*
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> res(n);
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(n, 0);

    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      indegree[v]++;
    }

    // toppological sorting
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      topoOrder.push_back(curr);

      for (auto &v : adj[curr])
      {
        indegree[v]--;
        if (indegree[v] == 0)
          q.push(v);
      }
    }

    vector<unordered_set<int>> vec(n);
    for (auto &node : topoOrder)
    {
      for (auto &v : adj[node])
      {
        vec[v].insert(node);
        vec[v].insert(vec[node].begin(), vec[node].end());
      }
    }

    for (int i = 0; i < n; i++)
    {
      res[i] = vector<int>(vec[i].begin(), vec[i].end());
      sort(res[i].begin(), res[i].end());
    }

    return res;
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}};
  vector<vector<int>> res = obj.getAncestors(6, edges);
  for (auto &v : res)
  {
    for (auto &i : v)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}