/*
https://leetcode.com/problems/search-in-a-binary-search-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
  TreeNode *searchBST(TreeNode *root, int val)
  {
    TreeNode *curr = root;

    while (curr)
    {
      if (val == curr->val)
        return curr;
      else if (val < curr->val)
        curr = curr->left;
      else
        curr = curr->right;
    }

    return curr;
  }
};

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  Solution s;
  TreeNode *res = s.searchBST(root, 2);
  cout << res->val << endl;

  return 0;
}