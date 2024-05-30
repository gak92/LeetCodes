/*
https://leetcode.com/problems/is-graph-bipartite/submissions/1272489114/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool checkBipartiteBFS(vector<vector<int>> &adj, int currNode, vector<int> colors, int currColor)
  {
    queue<int> q;
    q.push(currNode);
    colors[currNode] = currColor;

    while (!q.empty())
    {
      int u = q.front();
      q.pop();

      for (auto &v : adj[u])
      {
        if (colors[v] == colors[u])
          return false;

        if (colors[v] == -1) // not visited
        {
          colors[v] = 1 - colors[u];
          q.push(v);
        }
      }
    }

    return true;
  }

public:
  bool isBipartite(vector<vector<int>> &adj)
  {
    int V = adj.size();
    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++)
    {
      if (colors[i] == -1)
      {
        if (checkBipartiteBFS(adj, i, colors, 1) == false)
          return false;
      }
    }

    return true;
  }
};

int main()
{
  vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  Solution s;
  cout << s.isBipartite(adj) << endl;

  return 0;
}