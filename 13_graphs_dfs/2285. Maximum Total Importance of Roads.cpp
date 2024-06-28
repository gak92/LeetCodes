/*
https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maximumImportance(int n, vector<vector<int>> &roads)
  {
    vector<int> degree(n, 0);

    for (auto &road : roads)
    {
      int u = road[0];
      int v = road[1];

      degree[u]++;
      degree[v]++;
    }

    sort(degree.begin(), degree.end());

    long long value = 1;
    long long res = 0;

    for (int i = 0; i < degree.size(); i++)
    {
      res += degree[i] * value;
      value++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {2, 5}};
  cout << s.maximumImportance(6, roads) << endl;

  return 0;
}