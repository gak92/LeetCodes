/*
https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
private:
    bool boxValid(vector<vector<char>>& board, int sr, int er, int sc, int ec)
    {
        unordered_set<char> st;
        for(int r=sr; r<er; r++) {
            for(int c=sc; c<ec; c++) {
                if(board[r][c] == '.') continue;
                if(st.find(board[r][c]) != st.end())
                    return false;
                st.insert(board[r][c]);
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate row
        cout << "start row checking..." << endl;
        for(int r=0; r<9; r++) {
            unordered_set<char> st;
            for(int c=0; c<9; c++) {
                if(board[r][c] == '.')  continue;
                if(st.find(board[r][c]) != st.end())
                    return false;
                st.insert(board[r][c]);
            }
        }

        // validate col
        cout << "start col checking..." << endl;
        for(int c=0; c<9; c++) {
            unordered_set<char> st;
            for(int r=0; r<9; r++) {
                if(board[r][c] == '.')  continue;
                if(st.find(board[r][c]) != st.end())
                    return false;
                st.insert(board[r][c]);
            }
        }

        // validate box
        cout << "start box checking..." << endl;
        for(int sr=0; sr<9; sr+=3) {
            int er = sr + 3;
            for(int sc=0; sc<9; sc+=3) {
                int ec = sc + 3;
                if(!boxValid(board, sr, er, sc, ec))
                    return false;
            }
        }

        return true;
    }
};

*/

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    unordered_set<string> st;

    for (int r = 0; r < 9; r++)
    {
      for (int c = 0; c < 9; c++)
      {
        if (board[r][c] == '.')
          continue;

        string row = string(1, board[r][c]) + "_ROW_" + to_string(r);
        string col = string(1, board[r][c]) + "_COL_" + to_string(c);
        string box = string(1, board[r][c]) + "_BOX_" + to_string(r / 3) + "_" + to_string(c / 3);

        if (st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end())
          return false;

        st.insert(row);
        st.insert(col);
        st.insert(box);
      }
    }

    return true;
  }
};

int main()
{
  return 0;
}