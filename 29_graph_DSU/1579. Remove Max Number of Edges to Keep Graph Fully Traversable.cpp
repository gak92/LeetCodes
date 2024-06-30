/*
https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/?envType=daily-question&envId=2024-06-30
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
  vector<int> parent;
  vector<int> rank;
  int components;

  DSU(int n)
  {
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;

    rank.resize(n + 1);
    components = n;
  }

  int find(int x)
  {
    if (x == parent[x])
      return x;

    return parent[x] = find(parent[x]);
  }

  void Union(int x, int y)
  {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
      return;

    if (rank[x_parent] > rank[y_parent])
      parent[y_parent] = x_parent;
    else if (rank[x_parent] < rank[y_parent])
      parent[x_parent] = y_parent;
    else
    {
      parent[x_parent] = y_parent;
      rank[y_parent]++;
    }

    components--;
  }

  bool isSingleComponent()
  {
    return components == 1;
  }
};

class Solution
{
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
  {
    DSU alice(n);
    DSU bob(n);

    auto lambda = [](vector<int> &a, vector<int> &b)
    {
      return a[0] > b[0];
    };

    sort(edges.begin(), edges.end(), lambda);

    int edgeCount = 0;

    for (auto &edge : edges)
    {
      int type = edge[0];
      int u = edge[1];
      int v = edge[2];

      if (type == 3)
      {
        bool isEdgeAdded = false;

        // for alice
        if (alice.find(u) != alice.find(v))
        {
          alice.Union(u, v);
          isEdgeAdded = true;
        }

        // for bob
        if (bob.find(u) != bob.find(v))
        {
          bob.Union(u, v);
          isEdgeAdded = true;
        }

        if (isEdgeAdded)
          edgeCount++;
      }
      else if (type == 2)
      {
        // bob
        if (bob.find(u) != bob.find(v))
        {
          bob.Union(u, v);
          edgeCount++;
        }
      }
      else
      {
        // alice
        if (alice.find(u) != alice.find(v))
        {
          alice.Union(u, v);
          edgeCount++;
        }
      }
    }

    if (alice.isSingleComponent() == true && bob.isSingleComponent() == true)
      return edges.size() - edgeCount;

    return -1;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
  cout << s.maxNumEdgesToRemove(4, edges) << endl;

  return 0;
}