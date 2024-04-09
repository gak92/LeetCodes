/*
https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75
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
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (!root)
      return NULL;

    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else
    {
      if (!root->left)
        return root->right;
      else if (!root->right)
        return root->left;

      TreeNode *curr = root->right;
      while (curr->left)
        curr = curr->left;

      root->val = curr->val;
      root->right = deleteNode(root->right, root->val);
    }

    return root;
  }
};

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  Solution *obj = new Solution();
  obj->deleteNode(root, 3);

  return 0;
}