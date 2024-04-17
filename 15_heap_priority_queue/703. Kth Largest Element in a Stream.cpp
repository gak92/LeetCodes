/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
private:
  int K;
  priority_queue<int, vector<int>, greater<int>> pq;

public:
  KthLargest(int k, vector<int> &nums)
  {
    K = k;
    for (int &num : nums)
    {
      pq.push(num);
      if (pq.size() > K)
        pq.pop();
    }
  }

  int add(int val)
  {
    pq.push(val);
    if (pq.size() > K)
      pq.pop();

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
  vector<int> nums = {4, 5, 8, 2};
  KthLargest *obj = new KthLargest(3, nums);
  cout << obj->add(3) << endl;
  cout << obj->add(5) << endl;
  cout << obj->add(10) << endl;
  cout << obj->add(9) << endl;
  cout << obj->add(4) << endl;
  return 0;
}