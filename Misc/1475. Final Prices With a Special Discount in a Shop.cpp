/*
https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/submissions/1215322847/
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Solution 2 - Using stack - O(n)
class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    stack<int> st;
    vector<int> res = prices;

    for (int i = 0; i < prices.size(); i++)
    {
      while (!st.empty() && prices[st.top()] >= prices[i])
      {
        res[st.top()] = prices[st.top()] - prices[i];
        st.pop();
      }

      st.push(i);
    }

    return res;
  }
};

// Solution 1 - Using two for loops - O(n^2)
// class Solution
// {
// public:
//   vector<int> finalPrices(vector<int> &prices)
//   {

//     for (int i = 0; i < prices.size(); i++)
//     {
//       for (int j = i + 1; j < prices.size(); j++)
//       {
//         if (prices[j] <= prices[i])
//         {
//           prices[i] -= prices[j];
//           break;
//         }
//       }
//     }

//     return prices;
//   }
// };

int main()
{
  vector<int> prices = {8, 4, 6, 2, 3};
  Solution sol;
  vector<int> res = sol.finalPrices(prices);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}