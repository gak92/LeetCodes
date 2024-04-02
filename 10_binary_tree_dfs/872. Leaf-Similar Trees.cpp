/*
https://leetcode.com/problems/leaf-similar-trees/description/?envType=study-plan-v2&envId=leetcode-75
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
  void dfs(TreeNode *root, vector<int> &leaves)
  {
    if (!root)
      return;

    if (!root->left && !root->right)
    {
      leaves.push_back(root->val);
      return;
    }

    dfs(root->left, leaves);
    dfs(root->right, leaves);
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {
    vector<int> leaves1;
    vector<int> leaves2;

    dfs(root1, leaves1);
    dfs(root2, leaves2);

    return leaves1 == leaves2;
  }
};

int main()
{
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(5);
  root1->right = new TreeNode(1);
  root1->left->left = new TreeNode(6);
  root1->right->right = new TreeNode(8);

  TreeNode *root2 = new TreeNode(3);
  root2->left = new TreeNode(5);
  root2->right = new TreeNode(1);

  Solution s;
  assert(!s.leafSimilar(root1, root2));
  return 0;
}