/*
https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool hasCycle;

  void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion, stack<int> &st)
  {
    visited[u] = true;
    inRecursion[u] = true;

    for (auto &v : adj[u])
    {
      if (inRecursion[v])
      {
        hasCycle = true;
        return;
      }

      if (!visited[v])
      {
        dfs(adj, v, visited, inRecursion, st);
      }
    }

    st.push(u);
    inRecursion[u] = false;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(numCourses, false);
    vector<bool> inRecursion(numCourses, false);
    stack<int> st;
    hasCycle = false;
    vector<int> res;

    // create adjacency list (Graph)
    for (auto &vec : prerequisites)
    {
      int a = vec[0];
      int b = vec[1];
      adj[b].push_back(a); // b ---> a
    }

    // call dfs
    for (int i = 0; i < numCourses; i++)
    {
      if (!visited[i])
        dfs(adj, i, visited, inRecursion, st);
    }

    if (hasCycle)
      return {};

    while (!st.empty())
    {
      res.push_back(st.top());
      st.pop();
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  vector<int> res = s.findOrder(4, prerequisites);

  for (auto &i : res)
    cout << i << " ";

  return 0;
}