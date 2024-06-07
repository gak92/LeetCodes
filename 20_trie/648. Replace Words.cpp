/*
https://leetcode.com/problems/replace-words/description/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  struct trieNode
  {
    bool isEndOfWord;
    trieNode *children[26];
  };

  trieNode *getNode()
  {
    trieNode *newNode = new trieNode();

    newNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
    {
      newNode->children[i] = NULL;
    }

    return newNode;
  }

  trieNode *root;

  void insert(string word)
  {
    trieNode *curr = root;

    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
      {
        curr->children[idx] = getNode();
      }

      curr = curr->children[idx];
    }

    curr->isEndOfWord = true;
  }

  string search(string word)
  {
    trieNode *curr = root;

    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        return word;

      curr = curr->children[idx];
      if (curr->isEndOfWord)
        return word.substr(0, i + 1);
    }

    return word;
  }

public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {

    root = getNode();
    for (auto &word : dictionary)
    {
      insert(word);
    }

    string res;
    string word;
    stringstream ss(sentence);

    while (getline(ss, word, ' '))
    {
      res += search(word) + " ";
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