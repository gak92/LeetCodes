/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150
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
  int dfs(TreeNode *root, int currSum)
  {
    if (root == NULL)
      return 0;

    currSum = (currSum * 10) + root->val;
    if (root->left == NULL && root->right == NULL)
      return currSum;

    int leftSum = dfs(root->left, currSum);
    int rightSum = dfs(root->right, currSum);

    return leftSum + rightSum;
  }

public:
  int sumNumbers(TreeNode *root)
  {
    int currSum = 0;
    return dfs(root, currSum);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  Solution s;
  cout << s.sumNumbers(root) << endl;

  return 0;
}