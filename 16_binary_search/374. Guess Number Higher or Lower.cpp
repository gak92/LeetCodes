/*
https://leetcode.com/problems/guess-number-higher-or-lower/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
private:
  int guess(int num)
  {
    int pick = (rand() % 10) + 1;
    if (num == pick)
      return 0;
    else if (num < pick)
      return 1;
    else
      return -1;
  }

public:
  int guessNumber(int n)
  {
    int l = 1;
    int r = n;

    while (l <= r)
    {
      int guessNum = l + (r - l) / 2;
      int val = guess(guessNum);

      if (val == 0)
        return guessNum;
      else if (val == -1)
        r = guessNum - 1;
      else
        l = guessNum + 1;
    }

    return -1;
  }
};

int main()
{
  Solution s;
  cout << s.guessNumber(10) << endl;

  return 0;
}