/*

https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    vector<bool> res;
    int max_ele = candies[0];
    for (int i = 1; i < candies.size(); i++)
    {
      if (candies[i] > max_ele)
        max_ele = candies[i];
    }

    cout << max_ele << endl;

    for (int i = 0; i < candies.size(); i++)
    {
      if (candies[i] + extraCandies >= max_ele)
        res.push_back(true);
      else
        res.push_back(false);
    }

    return res;
  }
};

int main()
{
  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;
  Solution s;
  vector<bool> res = s.kidsWithCandies(candies, extraCandies);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}