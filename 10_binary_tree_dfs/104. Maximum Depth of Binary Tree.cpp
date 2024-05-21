/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
  int maxDepth(TreeNode *root)
  {

    // ===================================================================
    // Solution # 03 - Iterative (Depth First Search)
    // ===================================================================

    if (root == NULL)
      return 0;

    stack<pair<TreeNode *, int>> stk;
    stk.push({root, 1});
    int res = 1;

    while (!stk.empty())
    {
      pair<TreeNode *, int> front = stk.top();
      stk.pop();
      res = max(res, front.second);

      if (front.first->left != NULL)
        stk.push({front.first->left, front.second + 1});

      if (front.first->right != NULL)
        stk.push({front.first->right, front.second + 1});
    }

    return res;

    // ===================================================================
    // Solution # 02 - Iterative (Breadth First Search)
    // ===================================================================

    // if(root == NULL)
    //     return 0;

    // queue<TreeNode*> q;
    // q.push(root);
    // int level = 0;

    // while(!q.empty())
    // {
    //     int size = q.size();
    //     for(int i=0; i<size; i++)
    //     {
    //         TreeNode* node = q.front();
    //         q.pop();
    //         if(node->left != NULL)
    //             q.push(node->left);

    //         if(node->right != NULL)
    //             q.push(node->right);
    //     }

    //     level++;
    // }

    // return level;

    // ===================================================================
    // Solution # 01 - Recursive (Depth First Search)
    // ===================================================================

    // if(root == NULL)
    //     return 0;

    // int left = maxDepth(root->left);
    // int right = maxDepth(root->right);

    // return 1 + max(left, right);
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution *obj = new Solution();
  cout << obj->maxDepth(root) << endl;

  return 0;
}