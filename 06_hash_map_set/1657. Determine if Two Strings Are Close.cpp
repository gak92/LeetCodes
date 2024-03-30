/*
https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool closeStrings(string word1, string word2)
  {
    vector<int> freq1(26, 0), freq2(26, 0);
    vector<int> present1(26, 0), present2(26, 0);

    for (const auto &ch : word1)
    {
      freq1[ch - 'a']++;
      present1[ch - 'a'] = 1;
    }

    for (const auto &ch : word2)
    {
      freq2[ch - 'a']++;
      present2[ch - 'a'] = 1;
    }

    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return (freq1 == freq2) && (present1 == present2);
  }
};

int main()
{
  Solution s;
  cout << s.closeStrings("abc", "bca") << endl; // true

  return 0;
}