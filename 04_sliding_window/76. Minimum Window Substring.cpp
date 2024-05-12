/*
https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int n = s.length();
    if (t.length() > n)
      return "";

    unordered_map<char, int> mp; // create map and add frequency of each char
    for (auto &ch : t)
      mp[ch]++;

    int i = 0;
    int j = 0;
    int requiredCount = t.length(); // how many char to look for in s
    int start_i = 0;                // save index of i of shortest window
    int minWindowSize = INT_MAX;

    while (j < n)
    {
      char ch = s[j];
      if (mp[ch] > 0) // check if char in mp
        requiredCount--;

      mp[ch]--;

      while (requiredCount == 0)
      {
        // start shrinking the window
        int currWindowSize = j - i + 1;
        if (currWindowSize < minWindowSize)
        {
          minWindowSize = currWindowSize;
          start_i = i;
        }

        mp[s[i]]++;
        if (mp[s[i]] > 0)
          requiredCount++;

        i++;
      }

      j++;
    }

    return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
  }
};

int main()
{
  Solution s;
  cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;

  return 0;
}