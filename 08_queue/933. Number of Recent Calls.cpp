/*
https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
  queue<int> requests;
  RecentCounter()
  {
  }

  int ping(int t)
  {
    requests.push(t);
    while (requests.front() < t - 3000)
    {
      requests.pop();
    }

    return requests.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
  RecentCounter *obj = new RecentCounter();
  cout << obj->ping(1) << endl;
  cout << obj->ping(100) << endl;
  cout << obj->ping(3001) << endl;
  cout << obj->ping(3002) << endl;
  return 0;
}