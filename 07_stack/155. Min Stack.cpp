/*
https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class MinStack {
private:
    stack<int> originalStack;
    stack<int> minStack;
public:
    MinStack() {

    }

    void push(int val) {
        if(minStack.empty() || val <= minStack.top())
            minStack.push(val);
        originalStack.push(val);
    }

    void pop() {
        if(originalStack.top() == minStack.top())
            minStack.pop();
        originalStack.pop();
    }

    int top() {
        return originalStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
*/

class MinStack
{
private:
  stack<int> stk;
  stack<int> minStk;

public:
  MinStack()
  {
  }

  void push(int val)
  {
    stk.push(val);                                       // just push value into main stack
    val = min(val, minStk.empty() ? val : minStk.top()); // update val whichever is minimum
    minStk.push(val);
  }

  void pop()
  {
    stk.pop();
    minStk.pop();
  }

  int top()
  {
    return stk.top();
  }

  int getMin()
  {
    return minStk.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  cout << obj->getMin() << endl; // return -3
  obj->pop();
  cout << obj->top() << endl;    // return 0
  cout << obj->getMin() << endl; // return -2

  return 0;
}