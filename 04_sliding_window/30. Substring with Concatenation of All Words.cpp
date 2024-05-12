/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
  HARD Question:
                Not fully clear,
                need to do it again...

*/

class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    unordered_map<string, int> wordFreq, currFreq;
    for (auto &word : words)
      wordFreq[word]++;

    int stringLen = s.length(); // string length
    int n = words.size();       // length of the words vector
    int wordLen = words[0].size();
    int windowSize = wordLen * n;
    vector<int> res;

    for (int startPos = 0; startPos < wordLen; startPos++)
    {
      int start = startPos;
      while (start + windowSize - 1 < stringLen)
      {

        currFreq = wordFreq;
        string currWord;
        bool matched = true; // assume matched found

        for (int i = 0; i < n; i++)
        {
          currWord = s.substr(start + i * wordLen, wordLen); // extract current word
          if (!currFreq.count(currWord) or currFreq[currWord] == 0)
          {                  // match current word
            matched = false; // not matched
            break;
          }
          currFreq[currWord]--; // decrement the frequency of current word
        }

        if (matched) // if matched found
          res.push_back(start);
        start += wordLen;
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<string> words = {"foo", "bar"};
  string str = "barfoothefoobarman";
  vector<int> res = s.findSubstring(str, words);
  for (auto &i : res)
    cout << i << " ";
  cout << endl;

  return 0;
}