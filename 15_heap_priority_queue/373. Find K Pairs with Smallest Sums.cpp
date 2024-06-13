/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 2- Using min heap (optimal approach)
/*

class Solution {
typedef pair<int, pair<int, int>> P;

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<P, vector<P>, greater<P>> pq;        // min heap
        set<pair<int, int>> visited;
        vector<vector<int>> res;

        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visited.insert({0, 0});

        while(k-- && !pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            res.push_back({nums1[i], nums2[j]});

            // push(i, j+1) if possible
            if(j+1<n && visited.find({i, j+1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }

            // push (i+1, j) if possible
            if(i+1<m && visited.find({i+1, j}) == visited.end()) {
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
        }

        return res;
    }
};

*/

// Solution # 1- Brute Force using max heap
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