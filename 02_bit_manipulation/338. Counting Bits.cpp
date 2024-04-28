/*
https://leetcode.com/problems/counting-bits/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        for(int i=0; i<=n; i++) {
            res[i] = __builtin_popcount(i);
        }

        return res;
    }
};
*/
class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> res(n + 1);
    res[0] = 0;

    for (int i = 1; i <= n; i++)
    {
      if (i % 2 == 0)
        res[i] = res[i / 2];
      else
        res[i] = res[i / 2] + 1;
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> res = s.countBits(5);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  return 0;
}