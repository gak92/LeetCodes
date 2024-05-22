/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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
  TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx)
  {
    if (start > end)
      return NULL;

    int rootVal = preorder[idx];
    idx++;

    int i = start;
    for (; i <= end; i++)
    {
      if (inorder[i] == rootVal)
        break;
    }

    TreeNode *root = new TreeNode(rootVal);
    root->left = solve(preorder, inorder, start, i - 1, idx);
    root->right = solve(preorder, inorder, i + 1, end, idx);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int n = preorder.size();
    int idx = 0;

    return solve(preorder, inorder, 0, n - 1, idx);
  }
};

int main()
{
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  Solution obj;
  TreeNode *root = obj.buildTree(preorder, inorder);
  cout << root->val << endl;

  return 0;
}