/*
https://leetcode.com/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
  bool inOrder(TreeNode *root, TreeNode *&prev)
  {
    if (root == NULL)
      return true;

    bool leftTree = inOrder(root->left, prev);
    if (!leftTree)
      return false;

    if (prev != NULL && prev->val >= root->val)
      return false;

    prev = root;

    bool rightTree = inOrder(root->right, prev);
    if (!rightTree)
      return false;

    return true;
  }

public:
  bool isValidBST(TreeNode *root)
  {
    TreeNode *prev = NULL;
    return inOrder(root, prev);
  }
};

int main()
{
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  Solution obj;
  cout << obj.isValidBST(root) << endl;

  return 0;
}