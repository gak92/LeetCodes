/*
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches)
  {

    queue<int> q;
    for (int i = 0; i < students.size(); i++)
      q.push(students[i]);

    int i = 0;
    int ask = 0;

    while (!q.empty() && ask != q.size())
    {
      if (q.front() == sandwiches[i])
      {
        q.pop();
        i++;
        ask = 0;
      }
      else
      {
        q.push(q.front());
        q.pop();
        ask++;
      }
    }

    return q.size();

    // Solution # 01
    // unordered_map<int, int> freq;

    // for(int i=0; i<students.size(); i++)
    //     freq[students[i]]++;

    // for(auto& sandwich:sandwiches)
    // {
    //     if(freq[sandwich] == 0)
    //         break;
    //     else
    //         freq[sandwich]--;
    // }

    // int res = 0;
    // for(int i=0; i<freq.size(); i++)
    // {
    //     // cout << freq[i] << endl;
    //     res += freq[i];
    // }

    // return res;
  }
};

int main()
{
  Solution s;
  vector<int> students = {1, 1, 0, 0};
  vector<int> sandwiches = {0, 1, 0, 1};
  cout << s.countStudents(students, sandwiches) << endl;
  return 0;
}