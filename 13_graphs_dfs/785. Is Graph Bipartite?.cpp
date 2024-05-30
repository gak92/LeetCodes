/*
https://leetcode.com/problems/is-graph-bipartite/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool checkBipartiteDFS(vector<vector<int>> &adj, int currNode, vector<int> &colors, int currColor)
  {
    colors[currNode] = currColor;

    for (auto &nbr : adj[currNode])
    {
      if (colors[nbr] == currColor)
        return false;
      else if (colors[nbr] == -1)
      {
        int colorOfV = 1 - currColor;
        if (checkBipartiteDFS(adj, nbr, colors, colorOfV) == false)
          return false;
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
        if (checkBipartiteDFS(adj, i, colors, 1) == false)
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