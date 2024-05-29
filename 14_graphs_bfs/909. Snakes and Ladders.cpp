/*
https://leetcode.com/problems/snakes-and-ladders/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int n;
  pair<int, int> getCoordinates(int num)
  {
    int rowFromTop = (num - 1) / n;
    int rowFromBottom = (n - 1) - rowFromTop;

    int col = (num - 1) % n;

    if ((n % 2 == 1 && rowFromBottom % 2 == 1) || (n % 2 == 0 && rowFromBottom % 2 == 0)) // right to left
      col = (n - 1) - col;

    return make_pair(rowFromBottom, col);
  }

public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    n = board.size();
    queue<int> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int steps = 0;

    visited[n - 1][0] = true; // mark first cell visited
    q.push(1);

    while (!q.empty())
    {
      int qsize = q.size();

      while (qsize--)
      {
        int x = q.front();
        q.pop();

        if (x == n * n)
          return steps;

        for (int i = 1; i <= 6; i++)
        {
          int val = x + i;
          if (val > n * n)
            break;

          pair<int, int> coord = getCoordinates(val);
          int r = coord.first;
          int c = coord.second;

          if (visited[r][c])
            continue;

          visited[r][c] = true;
          if (board[r][c] == -1)
            q.push(val);
          else
            q.push(board[r][c]);
        }
      }

      steps++;
    }

    return -1;
  }
};

int main()
{
  vector<vector<int>> board = {
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 15, -1, -1, -1, -1}};

  Solution s;
  cout << s.snakesAndLadders(board) << endl;

  return 0;
}