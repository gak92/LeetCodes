/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    if (root == NULL)
      return {};

    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int qsize = q.size();
      TreeNode *node = NULL;
      vector<int> temp;

      for (int i = 0; i < qsize; i++)
      {
        node = q.front();
        q.pop();
        temp.push_back(node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      if (res.size() % 2 == 1)
        reverse(temp.begin(), temp.end());

      res.push_back(temp);
    }

    return res;
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  Solution s;
  vector<vector<int>> res = s.zigzagLevelOrder(root);
  for (auto i : res)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}