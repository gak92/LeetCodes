/*
https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150
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
  int getLeftHeight(TreeNode *root)
  {
    int height = 0;
    TreeNode *curr = root;
    while (curr != NULL)
    {
      curr = curr->left;
      height++;
    }

    return height;
  }

  int getRightHeight(TreeNode *root)
  {
    int height = 0;
    TreeNode *curr = root;
    while (curr != NULL)
    {
      curr = curr->right;
      height++;
    }
    return height;
  }

public:
  int countNodes(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);

    if (lh == rh)
    { // perfect binary tree
      return (pow(2, lh) - 1);
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->left->left = new TreeNode(8);

  Solution s;
  cout << s.countNodes(root) << endl;

  return 0;
}