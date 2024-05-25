/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/?envType=study-plan-v2&envId=top-interview-150
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
  vector<double> averageOfLevels(TreeNode *root)
  {
    vector<double> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      double qsize = q.size();
      TreeNode *node = NULL;
      double total = 0;

      for (int i = 0; i < qsize; i++)
      {
        node = q.front();
        q.pop();
        total += node->val;

        if (node->left)
          q.push(node->left);

        if (node->right)
          q.push(node->right);
      }

      res.push_back(total / qsize);
    }

    return res;
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution s;
  vector<double> res = s.averageOfLevels(root);

  for (auto i : res)
  {
    cout << i << " ";
  }

  return 0;
}