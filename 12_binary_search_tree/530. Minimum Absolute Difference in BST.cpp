/*
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150
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
  int minDiff = INT_MAX;

  void inOrder(TreeNode *root, TreeNode *&prev)
  {
    if (root == NULL)
      return;

    inOrder(root->left, prev);

    if (prev != NULL)
      minDiff = min(minDiff, root->val - prev->val);

    prev = root;
    inOrder(root->right, prev);
  }

public:
  int getMinimumDifference(TreeNode *root)
  {
    TreeNode *prev = NULL;
    inOrder(root, prev);
    return minDiff;
  }
};

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  Solution s;
  cout << s.getMinimumDifference(root) << endl;

  return 0;
}