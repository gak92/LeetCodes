/*
https://leetcode.com/problems/keys-and-rooms/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(vector<vector<int>> &rooms, int source, vector<bool> &visited)
  {
    visited[source] = true;

    for (auto &room : rooms[source])
    {
      if (!visited[room])
        dfs(rooms, room, visited);
    }
  }

public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    int n = rooms.size();
    vector<bool> visited(n, false);

    dfs(rooms, 0, visited);

    for (bool x : visited)
    {
      if (x == false)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<vector<int>> &rooms = {{1}, {2}, {3}, {}};
  cout << sol->canVisitAllRooms(rooms) << endl;
  delete sol;

  return 0;
}