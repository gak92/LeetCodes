/*
https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minMutation(string startGene, string endGene, vector<string> &bank)
  {

    unordered_set<string> bankset(bank.begin(), bank.end());
    unordered_set<string> visited;

    queue<string> q;
    q.push(startGene);
    visited.insert(startGene);
    int level = 0;

    while (!q.empty())
    {
      int qsize = q.size();
      while (qsize--)
      {
        string curr = q.front();
        q.pop();

        if (curr == endGene)
          return level;

        for (char ch : "ACGT")
        {
          for (int i = 0; i < curr.length(); i++)
          {
            string nbr = curr;
            nbr[i] = ch;

            // if not visited and in the banset, then add it into the queue
            if (visited.find(nbr) == visited.end() && bankset.find(nbr) != bankset.end())
            {
              q.push(nbr);
              visited.insert(nbr);
            }
          }
        }
      }

      level++;
    }

    return -1;
  }
};

int main()
{
  Solution s;
  string startGene = "AACCGGTT";
  string endGene = "AACCGGTA";
  vector<string> bank = {"AACCGGTA"};

  cout << s.minMutation(startGene, endGene, bank) << endl;

  return 0;
}