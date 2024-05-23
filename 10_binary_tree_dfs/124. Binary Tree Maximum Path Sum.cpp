/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150
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
  int maxSum;
  int solve(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int leftSum = solve(root->left);
    int rightSum = solve(root->right);

    int pathFoundAtBottom = leftSum + rightSum + root->val;
    int onePathIsGood = max(leftSum, rightSum) + root->val;
    int onlyRootIsGood = root->val;

    maxSum = max({maxSum, pathFoundAtBottom, onePathIsGood, onlyRootIsGood});

    return max(onePathIsGood, onlyRootIsGood);
  }

public:
  int maxPathSum(TreeNode *root)
  {

    maxSum = INT_MIN;
    solve(root);
    return maxSum;
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

  Solution s;
  cout << s.maxPathSum(root) << endl;

  return 0;
}