/*
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
  int maxLevelSum(TreeNode *root)
  {
    if (!root)
      return 0;

    int maxSum = INT_MIN;
    int currLevel = 0;
    int maxLevel = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int levelSum = 0;
      currLevel++;
      int qlen = q.size();
      TreeNode *node = NULL;

      for (int i = 0; i < qlen; i++)
      {
        node = q.front();
        q.pop();
        levelSum += node->val;

        if (node->left)
          q.push(node->left);

        if (node->right)
          q.push(node->right);
      }

      if (levelSum > maxSum)
      {
        maxSum = levelSum;
        maxLevel = currLevel;
      }
    }

    return maxLevel;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  cout << Solution().maxLevelSum(root) << endl;

  return 0;
}