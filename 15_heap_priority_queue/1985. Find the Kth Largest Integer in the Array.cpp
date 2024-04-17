/*
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  struct comp
  {
    bool operator()(string &a, string &b)
    {
      if (a.size() == b.size())
        return a > b;
      return a.size() > b.size();
    }
  };

public:
  string kthLargestNumber(vector<string> &nums, int k)
  {

    // Solution # 02
    priority_queue<string, vector<string>, comp> pq;

    for (string &num : nums)
    {
      pq.push(num);
      if (pq.size() > k)
        pq.pop();
    }

    return pq.top();

    // Solution # 01
    // priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // for(auto& num:nums) {
    //     pq.push({num.length(), num});

    //     if(pq.size() > k)
    //         pq.pop();
    // }

    // return pq.top().second;
  }
};

int main()
{
  vector<string> nums = {"3", "6", "7", "10"};
  Solution sol;
  cout << sol.kthLargestNumber(nums, 4) << endl;
  return 0;
}