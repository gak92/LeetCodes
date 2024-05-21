/*
https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
  bool dfs(TreeNode *l, TreeNode *r)
  {
    if (l == NULL && r == NULL)
      return true;

    if (l == NULL || r == NULL)
      return false;

    if ((l->val == r->val) && dfs(l->left, r->right) && dfs(l->right, r->left))
      return true;

    return false;
  }

public:
  bool isSymmetric(TreeNode *root)
  {

    // Recursive - Depth First Search
    if (!root) // if root is NULL
      return true;

    return dfs(root->left, root->right);
  }
};

int main()
{
  Solution s;

  return 0;
}