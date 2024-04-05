/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
  int dfs(TreeNode *root, int maxVal)
  {
    if (root == NULL)
      return 0;

    int goodNodes = root->val >= maxVal ? 1 : 0;
    maxVal = max(maxVal, root->val);

    goodNodes += dfs(root->left, maxVal);
    goodNodes += dfs(root->right, maxVal);

    return goodNodes;
  }

  void dfs2(TreeNode *root, int maxSoFar, int &res)
  {
    if (root == NULL)
      return;

    if (root->val >= maxSoFar)
      res++;

    dfs2(root->left, max(maxSoFar, root->val), res);
    dfs2(root->right, max(maxSoFar, root->val), res);
  }

public:
  int goodNodes(TreeNode *root)
  {

    // solution # 02
    int res = 0;
    dfs2(root, root->val, res);
    return res;

    // solution # 01
    // return dfs(root, root->val);
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(5);
  Solution s;
  cout << s.goodNodes(root) << endl;

  return 0;
}