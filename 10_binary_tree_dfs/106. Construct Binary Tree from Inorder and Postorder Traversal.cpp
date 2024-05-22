/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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
  TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
  {
    if (inStart > inEnd)
      return NULL;

    int rootVal = postorder[postEnd];
    int i = inStart;
    for (; i <= inEnd; i++)
    {
      if (inorder[i] == rootVal)
        break;
    }

    int leftSize = i - inStart;
    int rightSize = inEnd - i;

    TreeNode *root = new TreeNode(rootVal);
    root->left = solve(inorder, postorder, inStart, i - 1, postStart, postStart + leftSize - 1);
    root->right = solve(inorder, postorder, i + 1, inEnd, postEnd - rightSize, postEnd - 1);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    int n = inorder.size();

    int inStart = 0;
    int inEnd = n - 1;

    int postStart = 0;
    int postEnd = n - 1;

    return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};
  TreeNode *root = sol->buildTree(inorder, postorder);
  // printTree(root);

  return 0;
}