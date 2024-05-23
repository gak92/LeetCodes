/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150
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
private:
  TreeNode *dfs(TreeNode *root)
  {
    if (root == NULL)
      return NULL;

    TreeNode *leftTail = dfs(root->left);
    TreeNode *rightTail = dfs(root->right);

    if (root->left)
    {
      leftTail->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }

    if (rightTail)
      return rightTail;
    else if (leftTail)
      return leftTail;

    return root;
  }

public:
  void flatten(TreeNode *root)
  {
    dfs(root);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  Solution s;
  s.flatten(root);

  return 0;
}