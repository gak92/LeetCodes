/*
https://leetcode.com/problems/replace-words/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  string findRoot(string &word, unordered_set<string> &set)
  {
    for (int l = 1; l <= word.length(); l++)
    {
      string root = word.substr(0, l);
      if (set.count(root)) // if found in set then return root word
        return root;
    }

    return word; // else return same word (no root found)
  }

public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {

    unordered_set<string> set(dictionary.begin(), dictionary.end());
    stringstream ss(sentence);
    string word;
    string res;

    while (getline(ss, word, ' '))
    { // get each word separate by spaces
      res += findRoot(word, set) + " ";
    }

    res.pop_back();
    return res;
  }
};

int main()
{

  vector<string> dictionary = {"cat", "bat", "rat"};
  string sentence = "the cattle was rattled by the battery";

  Solution s;
  cout << s.replaceWords(dictionary, sentence) << endl;

  return 0;
}