/*
https://leetcode.com/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token;
        int countWords;

        while(getline(ss, token, ' ')) {
            words.push_back(token);
            countWords++;
        }

        int n = pattern.length();
        if(n != countWords)
            return false;

        unordered_map<string, char> wordToChar;
        unordered_set<char> used;

        for(int i=0; i<n; i++) {
            string word = words[i];
            char ch = pattern[i];

            // if not present in map and not in set
            if(wordToChar.find(word) == wordToChar.end() && used.find(ch) == used.end()) {
                wordToChar[word] = ch;
                used.insert(ch);
            }
            else if(wordToChar[word] != ch) {
                return false;
            }
        }

        return true;
    }
};

*/

class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, int> charToIndex;
    unordered_map<string, int> wordToIndex;

    stringstream ss(s);
    string token;
    int wordCount = 0;
    int i = 0;
    int n = pattern.length();

    while (ss >> token)
    {
      wordCount++;
      char ch = pattern[i];

      if (i == n) // if pattern end, but we got token
        return false;
      if (charToIndex[ch] != wordToIndex[token]) // if index mismatched
        return false;

      charToIndex[ch] = i + 1;
      wordToIndex[token] = i + 1;
      i++;
    }

    if (wordCount != n || i != n)
      return false;

    return true;
  }
};

int main()
{
  Solution s;
  cout << s.wordPattern("abba", "dog cat cat dog") << endl;
  cout << s.wordPattern("abba", "dog cat cat fish") << endl;
  cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
  cout << s.wordPattern("abba", "dog dog dog dog") << endl;
  return 0;
}