/*
https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 2: Backtracking with Optimisation
/*
class Solution {
private:
    vector<string> res;

    void solve(string& curr, int n, int open, int close)
    {
        if(curr.length() == 2*n) {
            res.push_back(curr);
            return;
        }

        if(open < n) {
            curr.push_back('(');
            solve(curr, n, open+1, close);
            curr.pop_back();
        }

        if(close < open) {
            curr.push_back(')');
            solve(curr, n, open, close+1);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open  = 0;
        int close = 0;
        solve(curr, n, open, close);

        return res;
    }
};
*/

// Approach 1: Backtracking

class Solution
{
private:
  vector<string> res;

  bool isValid(string curr)
  {
    int count = 0;
    for (char ch : curr)
    {
      if (ch == '(')
        count++;
      else
        count--;
      if (count < 0)
        return false;
    }

    return count == 0;
  }

  void solve(string &curr, int n)
  {
    if (curr.length() == 2 * n)
    {
      if (isValid(curr))
      {
        res.push_back(curr);
      }
      return;
    }

    curr.push_back('(');
    solve(curr, n);
    curr.pop_back();

    curr.push_back(')');
    solve(curr, n);
    curr.pop_back();
  }

public:
  vector<string> generateParenthesis(int n)
  {
    string curr = "";
    solve(curr, n);

    return res;
  }
};

int main()
{
  Solution s;
  vector<string> res = s.generateParenthesis(3);

  for (auto &str : res)
    cout << str << " ";
  cout << endl;

  return 0;
}