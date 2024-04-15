/*
https://leetcode.com/problems/rotting-oranges/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool isValid(int newRow, int newCol, int m, int n)
  {
    if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n)
      return true;
    else
      return false;
  }

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int m = grid.size();    // no. of rows
    int n = grid[0].size(); // no. of columns
    int fresh = 0;
    queue<pair<int, int>> q;
    int time = 0;

    // push rotten oranges in queue and count fresh one
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2) // push rotten oranges in queue
          q.push({i, j});
        else if (grid[i][j] == 1) // count fresh orange
          fresh++;
      }
    }
    cout << "Fresh: " << fresh << endl;
    cout << "Q: " << q.front().first << ", " << q.front().second << endl;

    // directions
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    // BFS Traversal
    while (!q.empty() && fresh > 0)
    {
      int qsize = q.size();
      cout << "Qsize: " << qsize << endl;

      for (int i = 0; i < qsize; i++)
      {
        pair<int, int> p = q.front();
        q.pop();

        int row = p.first;
        int col = p.second;
        cout << "row, col: " << row << ", " << col << endl;

        for (int j = 0; j < 4; j++)
        { // traversing 4 direction
          int newRow = row + dr[j];
          int newCol = col + dc[j];

          if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n)
          {
            if (grid[newRow][newCol] == 1)
            {                           // if nebor oranges fresh
              grid[newRow][newCol] = 2; // make it rotten
              q.push({newRow, newCol});
              fresh--;
            }

          } // end of if
          cout << "fresh: " << fresh << endl;
        } // end of direction for loop

      } // end of for loop
      // time++;
      time++;
      cout << "Time: " << time << endl;

    } // end of while loop

    return (fresh == 0) ? time : -1;
  }
};

int main()
{
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  Solution s;
  cout << s.orangesRotting(grid) << endl;

  return 0;
}