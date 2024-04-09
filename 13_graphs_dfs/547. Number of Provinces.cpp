/*
https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02 - Using Adjacency Matrix and DFS
class Solution
{
private:
  int n;
  void dfs(vector<vector<int>> &isConnected, int u, vector<bool> &visited)
  {
    visited[u] = true;
    for (int v = 0; v < n; v++)
    {
      if (!visited[v] && isConnected[u][v] == 1)
        dfs(isConnected, v, visited);
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    n = isConnected.size();
    vector<bool> visited(n, false);
    int count = 0;

    // call dfs
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        count++;
        dfs(isConnected, i, visited);
      }
    }

    return count;
  }
};

// Solution # 01 - Using Adjacency List and DFS
/*
class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited)
    {
        visited[u] = true;
        for(int& v:adj[u]) {
            if(!visited[v])
                dfs(adj, v, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        // make graph
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // call dfs
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }


        return count;
    }
};

*/

int main()
{
  Solution s;
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << s.findCircleNum(isConnected) << endl;
  return 0;
}