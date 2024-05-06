/*
https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    int n = citations.size();
    vector<int> vec(n + 1, 0);

    for (auto &c : citations)
    { // kind of a count sort
      // cout << c << endl;
      if (c > n)
        vec[n]++;
      else
        vec[c]++;
    }

    int count = 0;
    for (int i = n; i >= 0; i--)
    {                         // now traverse backward
      count = count + vec[i]; // adding count value
      if (count >= i)         // if ith research paper has citation equal to ith or more, return it
        return i;
    }

    return 0;
  }
};

int main()
{
  Solution s;
  vector<int> citations = {3, 0, 6, 1, 5};
  cout << s.hIndex(citations) << endl;

  return 0;
}