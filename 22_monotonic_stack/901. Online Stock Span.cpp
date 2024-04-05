/*
https://leetcode.com/problems/online-stock-span/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
  stack<pair<int, int>> stk;
  StockSpanner()
  {
  }

  int next(int price)
  {
    int span = 1;
    while (!stk.empty() && stk.top().first <= price)
    {
      span += stk.top().second;
      stk.pop();
    }
    stk.push({price, span});

    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{

  StockSpanner *obj = new StockSpanner();
  cout << obj->next(100) << endl;
  cout << obj->next(80) << endl;
  cout << obj->next(60) << endl;
  cout << obj->next(70) << endl;
  cout << obj->next(60) << endl;
  cout << obj->next(75) << endl;
  cout << obj->next(85) << endl;
  return 0;
}