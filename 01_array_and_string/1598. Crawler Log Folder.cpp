/*
https://leetcode.com/problems/crawler-log-folder/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    int depth = 0;

    for (auto &log : logs)
    {
      if (log == "../")
        depth = max(0, depth - 1);
      else if (log == "./")
        continue;
      else
        depth++;
    }

    return depth;
  }
};

int main()
{
  Solution s;
  vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  cout << s.minOperations(logs) << endl;

  return 0;
}