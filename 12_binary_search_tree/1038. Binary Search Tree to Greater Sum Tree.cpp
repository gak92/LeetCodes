/*
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25
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
  void solve(TreeNode *root, int &total)
  {
    if (!root)
      return;

    solve(root->right, total);
    total += root->val;
    root->val = total;
    solve(root->left, total);
  }

public:
  TreeNode *bstToGst(TreeNode *root)
  {
    int total = 0;

    solve(root, total);

    return root;
  }
};

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(1);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(2);
  root->left->right->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  root->right->right->right = new TreeNode(8);

  Solution solution;
  TreeNode *res = solution.bstToGst(root);
  cout << res->val << endl;

  return 0;
}