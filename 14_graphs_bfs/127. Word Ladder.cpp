/*
https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> wordset(wordList.begin(), wordList.end());
    unordered_set<string> visited;

    queue<string> q;
    q.push(beginWord);
    visited.insert(beginWord);
    int res = 1;

    while (!q.empty())
    {
      int qsize = q.size();

      while (qsize--)
      {
        string currWord = q.front();
        q.pop();

        if (currWord == endWord)
          return res;

        for (int i = 0; i < 26; i++)
        {
          char ch = i + 'a';
          for (int j = 0; j < currWord.length(); j++)
          {
            string nbr = currWord;
            nbr[j] = ch;

            // if not visited, and word in wordset then push into q
            if (visited.find(nbr) == visited.end() && wordset.find(nbr) != wordset.end())
            {
              q.push(nbr);
              visited.insert(nbr);
            }
          }
        }
      }

      res++;
    }

    return 0;
  }
};

int main()
{

  Solution s;

  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  int res = s.ladderLength(beginWord, endWord, wordList);

  cout << res << endl;

  return 0;
}