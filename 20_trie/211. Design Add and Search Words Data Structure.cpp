/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
private:
  struct TrieNode
  {
    bool isEndOfWord;
    TrieNode *children[26];
  };

  TrieNode *getNode()
  {
    TrieNode *newNode = new TrieNode();
    newNode->isEndOfWord = false;

    for (int i = 0; i < 26; i++)
    {
      newNode->children[i] = NULL;
    }

    return newNode;
  }

  TrieNode *root;

public:
  WordDictionary()
  {
    root = getNode();
  }

  void addWord(string word)
  {
    TrieNode *curr = root;

    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        curr->children[idx] = getNode();

      curr = curr->children[idx];
    }

    curr->isEndOfWord = true;
  }

  bool searchUtil(TrieNode *root, string word)
  {
    TrieNode *curr = root;

    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      int idx = ch - 'a';

      if (ch == '.')
      {
        for (int j = 0; j < 26; j++)
        {
          if (curr->children[j] != NULL)
          {
            if (searchUtil(curr->children[j], word.substr(i + 1)) == true)
              return true;
          }
        }
        return false;
      }
      else if (curr->children[idx] == NULL)
      {
        return false;
      }

      curr = curr->children[idx];
    }

    if (curr != NULL && curr->isEndOfWord == true)
      return true;

    return false;
  }

  bool search(string word)
  {
    return searchUtil(root, word);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
  WordDictionary *obj = new WordDictionary();

  obj->addWord("bad");
  obj->addWord("dad");
  obj->addWord("mad");

  cout << obj->search("pad") << endl;
  cout << obj->search("bad") << endl;
  cout << obj->search(".ad") << endl;
  cout << obj->search("b..") << endl;

  return 0;
}