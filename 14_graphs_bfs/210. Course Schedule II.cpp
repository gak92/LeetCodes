/*
https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int numCourses, vector<int> &indegree)
  {
    queue<int> q;
    int count = 0;
    vector<int> res;

    for (int i = 0; i < numCourses; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
        count++;
        res.push_back(i);
      }
    }

    while (!q.empty())
    {
      int u = q.front();
      q.pop();

      for (auto &v : adj[u])
      {
        indegree[v]--;
        if (indegree[v] == 0)
        {
          q.push(v);
          count++;
          res.push_back(v);
        }
      }
    }

    if (count == numCourses) // I took all courses
      return res;

    return {}; // I can't take all courses, bcoz of cycle
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    unordered_map<int, vector<int>> adj; // create adjacency list
    vector<int> indegree(numCourses, 0); // Kahn's Algo (maintain indegree)

    for (auto &vec : prerequisites)
    {
      int a = vec[0];
      int b = vec[1];
      adj[b].push_back(a); // {a, b} ==> b ---> a (first do b, then a)
      indegree[a]++;
    }

    return topologicalSort(adj, numCourses, indegree);
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  int numCourses = 4;

  vector<int> res = obj.findOrder(numCourses, prerequisites);

  for (auto &x : res)
    cout << x << " ";

  return 0;
}