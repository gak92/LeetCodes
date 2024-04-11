/*
https://leetcode.com/problems/evaluate-division/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string des, unordered_set<string> &visited, double product, double &res)
  {
    if (visited.find(src) != visited.end()) // if already visited then return
      return;

    visited.insert(src); // mark visited
    if (src == des)
    {
      res = product;
      return;
    }

    for (auto &p : adj[src])
    {
      string v = p.first;
      double val = p.second;

      dfs(adj, v, des, visited, product * val, res);
    }
  }

public:
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {

    // Make graph (adj)
    int n = equations.size();
    unordered_map<string, vector<pair<string, double>>> adj;

    for (int i = 0; i < n; i++)
    {
      string src = equations[i][0];               // "a"
      string des = equations[i][1];               // "b"
      adj[src].push_back({des, values[i]});       // "a/b"
      adj[des].push_back({src, 1.0 / values[i]}); // "b/a"
    }

    // result vector
    vector<double> result;

    for (auto &query : queries)
    {
      string src = query[0];
      string des = query[1];
      double res = -1.0;
      double product = 1.0;

      if (adj.find(src) != adj.end() && adj.find(des) != adj.end())
      {
        unordered_set<string> visited;
        dfs(adj, src, des, visited, product, res);
      }
      result.push_back(res);
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

  vector<double> result = s.calcEquation(equations, values, queries);

  cout << "[";
  for (auto r : result)
  {
    cout << r << ", ";
  }
  cout << "]" << endl;

  return 0;
}