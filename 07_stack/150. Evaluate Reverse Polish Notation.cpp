/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/*===========================================

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int (int, int)>> mp = {
            {"+", [](int num1, int num2) {return num1 + num2;} },
            {"-", [](int num1, int num2) {return num1 - num2;} },
            {"*", [](int num1, int num2) {return (long)num1 * (long)num2;} },
            {"/", [](int num1, int num2) {return num1 / num2;} }
        };

        for(string& token:tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                int res = mp[token](num1, num2);
                st.push(res);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

=============================================*/

/* ===========================================

class Solution {
private:
    int calculate(int num1, int num2, string token)
    {
        if(token == "+")
            return num1 + num2;
        if(token == "-")
            return num1 - num2;
        if(token == "*")
            return long(num1) * long(num2);
        if(token == "/")
            return num1 / num2;

        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string& token:tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                int res = calculate(num1, num2, token);
                st.push(res);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

=========================================== */

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;
    int val1, val2;

    for (auto c : tokens)
    {
      if (c == "+")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(val2 + val1);
      }
      else if (c == "-")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(val1 - val2);
      }
      else if (c == "*")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(val2 * val1);
      }
      else if (c == "/")
      {
        val2 = st.top();
        st.pop();
        val1 = st.top();
        st.pop();
        st.push(ceil(val1 / val2));
      }
      else
      {
        st.push(stoi(c));
      }
    }

    return st.top();
  }
};

int main()
{
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  Solution sol;
  cout << sol.evalRPN(tokens) << endl;
  return 0;
}