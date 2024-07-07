/*
https://leetcode.com/problems/water-bottles/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 02 - O(logn)
/*

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed     = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange)
        {
            int extraFullBottles = emptyBottles / numExchange;
            int remaining = emptyBottles % numExchange;

            consumed += extraFullBottles;
            emptyBottles = remaining + extraFullBottles;
        }

        return consumed;
    }
};

*/

// Solution # 01 - O(n)
class Solution
{
public:
  int numWaterBottles(int numBottles, int numExchange)
  {
    int consumed = 0;

    while (numBottles >= numExchange)
    {
      consumed += numExchange;
      numBottles -= numExchange;

      numBottles += 1;
    }

    return consumed + numBottles;
  }
};

int main()
{
  Solution obj;
  cout << obj.numWaterBottles(9, 3) << endl;
  cout << obj.numWaterBottles(15, 4) << endl;
  cout << obj.numWaterBottles(5, 5) << endl;
  cout << obj.numWaterBottles(2, 3) << endl;

  return 0;
}