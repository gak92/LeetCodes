/*
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int count = 0;
  void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int u, vector<bool> &visited)
  {
    if (visited[u])
      return;          // return if already visited
    visited[u] = true; // mark visited

    for (pair<int, int> p : adj[u])
    {
      int v = p.first;
      int d = p.second;
      if (!visited[v])
      {
        if (d == 1)
          count++;
        dfs(adj, v, visited);
      }
    }
  }

public:
  int minReorder(int n, vector<vector<int>> &connections)
  {

    // make graph using adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for (vector<int> &vec : connections)
    {
      int u = vec[0];
      int v = vec[1];
      adj[u].push_back({v, 1}); // 1 means outgoing direction
      adj[v].push_back({u, 0}); // 0 means incoming direction
    }

    vector<bool> visited(n, false);

    dfs(adj, 0, visited);

    return count;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  cout << s.minReorder(6, connections) << endl;

  return 0;
}