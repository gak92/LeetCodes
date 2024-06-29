/*
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(int ancestor, unordered_map<int, vector<int>> &adj, vector<vector<int>> &res, int currNode)
  {
    for (int &nbr : adj[currNode])
    {
      if (res[nbr].empty() || res[nbr].back() != ancestor)
      {
        res[nbr].push_back(ancestor);
        dfs(ancestor, adj, res, nbr);
      }
    }
  }

public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> res(n);
    unordered_map<int, vector<int>> adj;

    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
      int ancestor = i;
      dfs(ancestor, adj, res, i);
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 6}, {5, 6}};
  vector<vector<int>> res = s.getAncestors(7, edges);

  for (int i = 0; i < res.size(); i++)
  {
    cout << i << ": ";
    for (int &ancestor : res[i])
    {
      cout << ancestor << " ";
    }
    cout << endl;
  }

  return 0;
}