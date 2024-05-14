/*
https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.length() != t.length())
      return false;

    unordered_map<char, int> freq;
    for (char ch : s)
    {
      freq[ch]++;
    }

    for (char ch : t)
    {
      if (freq.find(ch) == freq.end() || freq[ch] == 0)
        return false;

      freq[ch]--;
    }

    return true;
  }
};

int main()
{
  Solution s;
  cout << s.isAnagram("anagram", "nagaram") << endl;
  cout << s.isAnagram("rat", "car") << endl;
  return 0;
}