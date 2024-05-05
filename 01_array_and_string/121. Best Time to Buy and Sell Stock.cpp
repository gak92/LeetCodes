/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxP = 0;

        while(r < prices.size()) {
            if(prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            }
            else {
                l = r;
            }
            r++;
        }

        return maxP;
    }
};

*/

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int left = 0; // buy here initially
    int profit = 0;

    for (int right = 1; right < prices.size(); right++)
    {
      if (prices[right] < prices[left]) // if found low price then buy
        left = right;

      profit = max(profit, prices[right] - prices[left]); //
    }

    return profit;
  }
};

int main()
{
  Solution s;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << s.maxProfit(prices) << endl;
  return 0;
}