/*
https://leetcode.com/problems/same-tree/?envType=study-plan-v2&envId=top-interview-150
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == NULL && q == NULL)
      return true;

    if (p == NULL || q == NULL)
      return false;

    if (p->val != q->val)
      return false;

    bool leftSubTree = isSameTree(p->left, q->left);
    bool rightSubTree = isSameTree(p->right, q->right);

    return leftSubTree && rightSubTree;
  }
};

int main()
{
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);

  Solution obj;
  cout << obj.isSameTree(root1, root2) << endl;

  return 0;
}