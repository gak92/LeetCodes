/*
https://leetcode.com/problems/fibonacci-number/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 03 - Time = O(n), Space = O(n) (Top Down) (Recursion + Memoization)
/*

class Solution {
private:
    int solve(int n, vector<int>& dp)
    {
        if(n <= 1)
            return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
public:
    int fib(int n) {
        if(n <= 1)
            return n;

        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};

*/

// Solution # 02 - Time = O(n), Space = O(n) (Bottom Up)
/*

class Solution {

public:
    int fib(int n) {
        if(n <= 1)
            return n;

        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

*/

// Solution # 01 - Time = O(n), Space = O(1)
class Solution
{

public:
  int fib(int n)
  {
    if (n <= 1)
      return n;

    int c;
    int a = 0, b = 1;

    for (int i = 1; i < n; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }

    return c;
  }
};

int main()
{
  Solution s;
  cout << s.fib(2) << endl;
  cout << s.fib(3) << endl;
  cout << s.fib(4) << endl;

  return 0;
}