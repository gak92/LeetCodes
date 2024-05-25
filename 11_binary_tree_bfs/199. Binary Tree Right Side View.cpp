/*
https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75
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

// Using DFS - PreOrder Traversal
/*

class Solution {
private:
    void preOrder(TreeNode* root, int level, vector<int>& res)
    {
        if(root == NULL)
            return;

        if(res.size() < level)
            res.push_back(root->val);

        preOrder(root->right, level+1, res);
        preOrder(root->left, level+1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        preOrder(root, 1, res);

        return res;
    }
};

*/

// Using BFS
class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> res;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
      TreeNode *rightSide = NULL;
      int qlen = q.size();

      for (int i = 0; i < qlen; i++)
      {
        rightSide = q.front();
        q.pop();

        if (rightSide->left)
          q.push(rightSide->left);

        if (rightSide->right)
          q.push(rightSide->right);
      }

      if (rightSide)
        res.push_back(rightSide->val);
    }

    return res;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  Solution s;
  vector<int> res = s.rightSideView(root);
  cout << "Right side view of binary tree: ";
  for (auto &i : res)
    cout << i << " ";
  cout << endl;

  return 0;
}