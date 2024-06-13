/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  typedef pair<int, pair<int, int>> P;

public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int m = nums1.size();
    int n = nums2.size();
    priority_queue<P, vector<P>> pq;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int sum = nums1[i] + nums2[j];

        if (pq.size() < k)
        {
          pq.push({sum, {i, j}});
        }
        else if (pq.top().first > sum)
        {
          pq.pop();
          pq.push({sum, {i, j}});
        }
        else
        {
          break;
        }
      }
    }

    vector<vector<int>> res;

    while (!pq.empty())
    {
      auto temp = pq.top();
      pq.pop();

      int i = temp.second.first;
      int j = temp.second.second;

      res.push_back({nums1[i], nums2[j]});
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1, 7, 11};
  vector<int> nums2 = {2, 4, 6};
  int k = 3;

  vector<vector<int>> res = s.kSmallestPairs(nums1, nums2, k);

  for (auto x : res)
  {
    for (auto y : x)
    {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}