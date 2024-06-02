/*
https://leetcode.com/problems/word-search-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int m, n;
  vector<string> res;

  struct trieNode
  {
    bool endOfWord;
    string word;
    trieNode *children[26];
  };

  trieNode *getNode()
  {
    trieNode *node = new trieNode();
    node->endOfWord = false;
    node->word = "";
    for (int i = 0; i < 26; i++)
    {
      node->children[i] = NULL;
    }

    return node;
  }

  void insert(trieNode *root, string word)
  {
    trieNode *crawler = root;

    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      int idx = ch - 'a';

      if (crawler->children[idx] == NULL)
        crawler->children[idx] = getNode();

      crawler = crawler->children[idx];
    }

    crawler->endOfWord = true;
    crawler->word = word;
  }

  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void findTrieWords(vector<vector<char>> &board, int i, int j, trieNode *root)
  {
    if (i < 0 || j < 0 || i >= m || j >= n)
      return;

    if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL)
      return;

    root = root->children[board[i][j] - 'a'];

    if (root->endOfWord == true)
    {
      res.push_back(root->word);
      root->endOfWord = false;
    }

    char temp = board[i][j];
    board[i][j] = '$'; // mark visited

    // go to all directions
    for (auto &dir : directions)
    {
      findTrieWords(board, i + dir[0], j + dir[1], root);
    }

    board[i][j] = temp; // backtracking
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    m = board.size();
    n = board[0].size();

    // create root
    trieNode *root = getNode();

    // insert all words in trie
    for (auto &word : words)
    {
      insert(root, word);
    }

    // traverse the board
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        char ch = board[i][j];
        if (root->children[ch - 'a'] != NULL)
          findTrieWords(board, i, j, root);
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<char>> board{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
  vector<string> words{"oath", "pea", "eat", "rain"};

  vector<string> res = s.findWords(board, words);
  for (auto &word : res)
  {
    cout << word << " ";
  }
  cout << endl;

  return 0;
}