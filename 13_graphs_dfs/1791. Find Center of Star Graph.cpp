/*
https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach # 02
/*

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        vector<int> first  = edges[0];
        vector<int> second = edges[1];

        if(first[0] == second[0] || first[0] == second[1])
            return first[0];

        return first[1];
    }
};

*/

class Solution
{
public:
  int findCenter(vector<vector<int>> &edges)
  {
    int n = edges.size();
    unordered_map<int, int> degrees;

    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];

      degrees[u]++;
      degrees[v]++;
    }

    for (auto &it : degrees)
    {
      if (it.second == n)
        return it.first;
    }

    return -1;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
  cout << s.findCenter(edges) << endl;

  return 0;
}