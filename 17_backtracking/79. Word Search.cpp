/*
https://leetcode.com/problems/word-search/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int m, n;
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  bool find(vector<vector<char>> &board, int i, int j, int idx, string &word)
  {
    if (idx == word.length())
      return true;

    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
      return false;

    if (board[i][j] != word[idx])
      return false;

    char temp = board[i][j];
    board[i][j] = '$'; // mark visited

    for (auto &dir : directions)
    {
      if (find(board, i + dir[0], j + dir[1], idx + 1, word))
        return true;
    }

    board[i][j] = temp; // backtracking
    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word[0] && find(board, i, j, 0, word))
          return true;
      }
    }

    return false;
  }
};

int main()
{
  Solution obj;
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  cout << obj.exist(board, word);

  return 0;
}