/*
https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
  struct trieNode
  {
    bool isWordEnd;
    trieNode *children[26];
  };

  trieNode *createNode()
  {
    trieNode *node = new trieNode();
    node->isWordEnd = false;
    for (int i = 0; i < 26; i++)
    {
      node->children[i] == NULL;
    }
    return node;
  }

  trieNode *root;

public:
  Trie()
  {
    root = createNode();
  }

  void insert(string word)
  {
    trieNode *curr = root;

    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        curr->children[idx] = createNode();

      curr = curr->children[idx];
    }
    curr->isWordEnd = true;
  }

  bool search(string word)
  {
    trieNode *curr = root;

    for (char ch : word)
    {
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        return false;

      curr = curr->children[idx];
    }

    return curr->isWordEnd;
  }

  bool startsWith(string prefix)
  {
    trieNode *curr = root;

    for (char ch : prefix)
    {
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        return false;

      curr = curr->children[idx];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
  Trie *obj = new Trie();
  obj->insert("apple");
  cout << obj->search("apple") << endl;   // returns true
  cout << obj->search("app") << endl;     // returns false
  cout << obj->startsWith("app") << endl; // returns true
  obj->insert("app");
  cout << obj->search("app") << endl; // returns true

  return 0;
}