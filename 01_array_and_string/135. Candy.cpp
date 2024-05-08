/*
https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int n = ratings.size();
    vector<int> count(n, 1);

    for (int i = 1; i < n; i++)
    {
      if (ratings[i] > ratings[i - 1])
        count[i] = max(count[i], count[i - 1] + 1);
    }

    for (int i = n - 2; i >= 0; i--)
    {
      if (ratings[i] > ratings[i + 1])
        count[i] = max(count[i], count[i + 1] + 1);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
      res += count[i];
    }

    return res;
  }
};

int main()
{
  vector<int> ratings = {1, 0, 2};
  Solution s;
  cout << s.candy(ratings) << endl;

  return 0;
}