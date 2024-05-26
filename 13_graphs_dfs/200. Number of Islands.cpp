/*
https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int m; // rows
  int n; // cols

  void dfs(vector<vector<char>> &grid, int i, int j)
  {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || grid[i][j] == '$')
      return;

    grid[i][j] = '$'; // mark visited

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }

  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void bfs(vector<vector<char>> &grid, int i, int j)
  {
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '$'; // mark visited;

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      for (auto &dir : directions)
      {
        int r = it.first + dir[0];
        int c = it.second + dir[1];

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
          continue;
        else
        {
          q.push({r, c});
          grid[r][c] = '$';
        }
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    m = grid.size();
    n = grid[0].size();
    int islands = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '1')
        {
          bfs(grid, i, j);
          islands++;
        }
      }
    }

    return islands;
  }
};

int main()
{
  Solution s;
  vector<vector<char>> grid = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}};

  cout << s.numIslands(grid) << endl;

  return 0;
}