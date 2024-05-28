/*
https://leetcode.com/problems/course-schedule/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion)
  {
    visited[u] = true;
    inRecursion[u] = true;

    for (auto &v : adj[u])
    {
      if (!visited[v] && isCycleDFS(adj, v, visited, inRecursion))
        return true;
      else if (inRecursion[v] == true)
        return true;
    }

    inRecursion[u] = false;
    return false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(numCourses, false);
    vector<bool> inRecursion(numCourses, false);

    // create adjacency list
    for (auto &vec : prerequisites)
    {
      int a = vec[0];
      int b = vec[1];

      // {a, b}  ===>   b ---> a , first b then a
      adj[b].push_back(a);
    }

    // call dfs for each node (course)
    for (int i = 0; i < numCourses; i++)
    {
      if (!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
        return false;
    }

    return true;
  }
};

int main()
{
  Solution s;

  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  int numCourses = 2;
  cout << s.canFinish(numCourses, prerequisites) << endl;

  return 0;
}