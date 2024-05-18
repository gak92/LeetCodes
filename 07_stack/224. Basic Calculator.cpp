/*
https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int n = s.length();
    stack<int> st;

    int number = 0;
    int res = 0;
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
      if (isdigit(s[i]))
      {
        number = number * 10 + (s[i] - '0');
      }
      else if (s[i] == '+')
      {
        res += number * sign;
        number = 0;
        sign = 1;
      }
      else if (s[i] == '-')
      {
        res += number * sign;
        number = 0;
        sign = -1;
      }
      else if (s[i] == '(')
      {
        st.push(res);
        st.push(sign);

        number = 0;
        res = 0;
        sign = 1;
      }
      else if (s[i] == ')')
      {
        res += (number * sign);
        number = 0;

        int stkSign = st.top();
        st.pop();
        int stkRes = st.top();
        st.pop();

        res *= stkSign;
        res += stkRes;
      }
    }

    res += (number * sign);
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.calculate("1 + 1") << endl;
  cout << s.calculate(" 2-1 + 2 ") << endl;
  cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;

  return 0;
}