/*
https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    stack<int> st;

    for (int i = 0; i < asteroids.size(); i++)
    {
      if (st.empty() || asteroids[i] > 0) // stack empty OR asteroid is +ve
      {
        st.push(asteroids[i]);
      }
      else // asteroid is -ve
      {
        while (true)
        {
          int top = st.top();
          if (top < 0) // both are -ve, in same direction
          {
            st.push(asteroids[i]);
            break;
          }
          else if (top == abs(asteroids[i])) // both are same size
          {
            st.pop();
            break;
          }
          else if (top > abs(asteroids[i])) // coming asteroid is small
          {
            break;
          }
          else // coming asteroid is large
          {
            st.pop();
            if (st.empty())
            {
              st.push(asteroids[i]);
              break;
            }
          }
        } // end of while loop
      }
    } // end of for loop

    vector<int> res(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
      res[i] = st.top();
      st.pop();
    }

    return res;
  }
};

/*




*/

int main()
{
  Solution s;
  vector<int> asteroids = {5, 10, -5};
  vector<int> res = s.asteroidCollision(asteroids);
  return 0;
}