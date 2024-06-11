/*
https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
  {
    map<int, int> mp;

    for (auto &num : arr1)
    {
      mp[num]++;
    }

    int i = 0;
    for (auto &num : arr2)
    {
      while (mp[num] > 0)
      {
        arr1[i] = num;
        i++;
        mp[num]--;
      }
    }

    for (auto &it : mp)
    {
      int freq = it.second;
      while (freq > 0)
      {
        arr1[i] = it.first;
        i++;
        freq--;
      }
    }

    return arr1;
  }
};

int main()
{
  Solution obj;
  vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
  vector<int> arr2 = {2, 1, 4, 3, 9, 6};
  vector<int> res = obj.relativeSortArray(arr1, arr2);

  for (auto &num : res)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}