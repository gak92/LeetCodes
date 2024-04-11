/*
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
  {
    int m = maze.size();    // no. of rows
    int n = maze[0].size(); // no. of columns

    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});   // push current standing position
    maze[entrance[0]][entrance[1]] = '+'; // mark current position visited

    int level = 0;
    int dr[4] = {1, -1, 0, 0}; // define down=[1][0], up=[-1][0], right=[0][1], left=[0][-1]
    int dc[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
      int qsize = q.size();
      level++;

      for (int i = 0; i < qsize; i++)
      {
        auto x = q.front();
        q.pop();

        int row = x.first;
        int col = x.second;

        for (int i = 0; i < 4; i++)
        {
          int newRow = row + dr[i];
          int newCol = col + dc[i];

          if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n)
          {
            if (maze[newRow][newCol] == '+') // if already visited or wall
              continue;

            if (newRow == 0 || newCol == 0 || newRow == m - 1 || newCol == n - 1) // if at boundary
              return level;

            q.push({newRow, newCol});   // push into the queue
            maze[newRow][newCol] = '+'; // mark visited
          }
        } // end of foor loop

      } // end of for loop
    }   // end of while loop

    return -1;
  }
};

int main()
{
  vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
  Solution sol;
  vector<int> entrance = {1, 2};
  cout << "Minimum steps to reach the exit: " << sol.nearestExit(maze, entrance) << endl;

  return 0;
}