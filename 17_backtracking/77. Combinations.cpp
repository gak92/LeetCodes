/*
https://leetcode.com/problems/combinations/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02
class Solution
{
private:
  vector<vector<int>> res;

  void solve(int start, int &n, int k, vector<int> &temp)
  {
    if (k == 0)
    {
      res.push_back(temp);
      return;
    }

    for (int i = start; i <= n; i++)
    {
      temp.push_back(i);
      solve(i + 1, n, k - 1, temp);
      temp.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<int> temp;

    solve(1, n, k, temp);

    return res;
  }
};

// Solution # 01
// class Solution
// {
// private:
//   vector<vector<int>> res;

//   void solve(int start, int &n, int k, vector<int> &temp)
//   {
//     if (k == 0)
//     {
//       res.push_back(temp);
//       return;
//     }

//     if (start > n)
//       return;

//     temp.push_back(start);
//     solve(start + 1, n, k - 1, temp);

//     temp.pop_back();
//     solve(start + 1, n, k, temp);
//   }

// public:
//   vector<vector<int>> combine(int n, int k)
//   {
//     vector<int> temp;

//     solve(1, n, k, temp);

//     return res;
//   }
// };

int main()
{
  Solution *obj = new Solution();
  vector<vector<int>> result = obj->combine(4, 2);

  for (auto i : result)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  delete obj;

  return 0;
}