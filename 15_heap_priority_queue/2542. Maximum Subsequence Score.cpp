/*
https://leetcode.com/problems/maximum-subsequence-score/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int n = nums1.size();
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
      vec[i] = {nums1[i], nums2[i]};
    }

    auto lambda = [&](auto &p1, auto &p2)
    {
      return p1.second > p2.second;
    };
    sort(vec.begin(), vec.end(), lambda);

    priority_queue<int, vector<int>, greater<int>> pq; // minheap

    long long kSum = 0;
    for (int i = 0; i <= k - 1; i++)
    {
      kSum += vec[i].first;
      pq.push(vec[i].first);
    }

    long long res = kSum * vec[k - 1].second;
    for (int i = k; i < n; i++)
    {
      kSum += vec[i].first - pq.top();
      pq.pop();

      pq.push(vec[i].first);
      res = max(res, kSum * vec[i].second);
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {2, 4, 5, 8, 10}, nums2 = {4, 6, 8, 9};
  int k = 3;
  cout << s.maxScore(nums1, nums2, k) << endl;

  return 0;
}