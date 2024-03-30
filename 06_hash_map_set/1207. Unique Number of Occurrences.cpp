/*
https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool uniqueOccurrences(vector<int> &arr)
  {
    unordered_map<int, int> map;
    unordered_set<int> set;

    for (const auto &num : arr)
    {
      map[num]++;
    }

    for (const auto &pair : map)
    {
      if (set.find(pair.second) == set.end())
        set.insert(pair.second);
      else
        return false;
    }

    return true;
  }
};

int main()
{
  vector<int> arr = {1, 2, 2, 1, 1, 3};
  Solution sol;
  cout << sol.uniqueOccurrences(arr) << endl;
  return 0;
}