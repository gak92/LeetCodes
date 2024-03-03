/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    int i = 0, j = 0;
    string res;

    while (i < word1.length() && j < word2.length())
    {
      cout << word1[i] << " " << endl;
      res.push_back(word1[i]);
      res.push_back(word2[j]);
      i++;
      j++;
    }

    while (i < word1.length())
    {
      res.push_back(word1[i]);
      i++;
    }

    while (j < word2.length())
    {
      res.push_back(word2[j]);
      j++;
    }

    return res;
  }
};

int main()
{
  Solution s;
  string word1 = "abc";
  string word2 = "pqr";
  cout << s.mergeAlternately(word1, word2) << endl;
  return 0;
}