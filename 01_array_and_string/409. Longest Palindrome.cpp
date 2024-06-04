/*
https://leetcode.com/problems/longest-palindrome/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution # 03 (using map and iterate only once)
/*

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int oddFreq = 0;

        for(auto& ch : s)
        {
            mp[ch]++;

            if(mp[ch] % 2 == 0)
                oddFreq--;
            else
                oddFreq++;
        }

        if(oddFreq > 0)
            return n - oddFreq + 1;

        return n;
    }
};

*/

// Solution # 02 (using map)
/*

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int res = 0;
        bool oddFreq = false;

        for(auto& ch : s)
            mp[ch]++;

        for(auto& it : mp)
        {
            if(it.second % 2 == 0) {
                res += it.second;
            }
            else {
                res += it.second - 1;
                oddFreq = true;
            }
        }

        if(oddFreq)
            res++;

        return res;
    }
};

*/

// Solution # 01

class Solution
{
public:
  int longestPalindrome(string s)
  {
    int n = s.length();
    unordered_set<char> set;
    int res = 0;

    for (auto &ch : s)
    {
      if (set.count(ch))
      {
        res += 2;
        set.erase(ch);
      }
      else
      {
        set.insert(ch);
      }
    }

    if (!set.empty())
      res++;

    return res;
  }
};

int main()
{
  Solution solution;
  cout << solution.longestPalindrome("abccccdd") << endl;

  return 0;
}
