/*
https://leetcode.com/problems/search-suggestions-system/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using two pointer approach
class Solution
{
public:
  vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
  {
    vector<vector<string>> res;
    sort(products.begin(), products.end());

    int l = 0;                   // left pointer
    int r = products.size() - 1; // right pointer

    for (int i = 0; i < searchWord.length(); i++)
    {
      char ch = searchWord[i];

      while (l <= r && (i >= products[l].length() || products[l][i] != ch))
      {
        l++;
      }
      while (l <= r && (i >= products[r].length() || products[r][i] != ch))
      {
        r--;
      }

      int remain = r - l + 1;
      int limit = min(3, remain);
      vector<string> temp;
      for (int j = 0; j < limit; j++)
      {
        temp.push_back(products[l + j]);
      }
      res.push_back(temp);
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
  vector<vector<string>> res = s.suggestedProducts(products, "mouse");
  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  // Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
  return 0;
}