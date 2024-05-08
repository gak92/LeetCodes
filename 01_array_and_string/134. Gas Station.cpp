/*
https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
// Brute Force - O(n^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i=0; i<n; i++) {
            if(gas[i] < cost[i])
                continue;

            int j = (i+1) % n;
            int currGas = gas[i] - cost[i] + gas[j];

            while(j != i) {
                if(currGas < cost[j])
                    break;

                int costToMoveFromj = cost[j];

                j = (j+1) % n;
                currGas = currGas - costToMoveFromj + gas[j];
            }

            if(j == i)
                return i;
        }

        return -1;
    }
};
*/

// Greedy - O(n)

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int n = gas.size();
    int totalEarn = accumulate(gas.begin(), gas.end(), 0);
    int totalExp = accumulate(cost.begin(), cost.end(), 0);

    if (totalEarn < totalExp)
      return -1;

    int resultIdx = 0;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
      total += gas[i] - cost[i];

      if (total < 0)
      {
        resultIdx = i + 1;
        total = 0;
      }
    }

    return resultIdx;
  }
};

int main()
{
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};

  Solution s;
  cout << s.canCompleteCircuit(gas, cost) << endl;

  return 0;
}