/*
https://leetcode.com/problems/course-schedule/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool checkTopologicalSort(unordered_map<int, vector<int>> &adj, int numCourses, vector<int> &indegree)
  {
    queue<int> q;
    int count = 0;

    for (int i = 0; i < numCourses; i++)
    {
      if (indegree[i] == 0)
      {
        count++;
        q.push(i);
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
          count++;
          q.push(v);
        }
      }
    }

    if (count == numCourses) // it means I can finish all courses
      return true;

    return false; // it means there is a cycle
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {

    unordered_map<int, vector<int>> adj; // Adjacency List
    vector<int> indegree(numCourses, 0); // Kahn's Algo

    for (auto &vec : prerequisites)
    {
      int a = vec[0];
      int b = vec[1];

      // do b course first, then a course,  b ---> a
      adj[b].push_back(a);

      // arrow pointed to a, increase indegree
      indegree[a]++;
    }

    // if cycle present, it means can't finish the courses
    return checkTopologicalSort(adj, numCourses, indegree);
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