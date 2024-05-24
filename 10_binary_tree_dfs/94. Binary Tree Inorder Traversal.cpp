/*
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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

/*

class Solution {
private:
    void dfsInorder(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
            return;

        dfsInorder(root->left, res);
        res.push_back(root->val);
        dfsInorder(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        dfsInorder(root, res);

        return res;
    }
};

*/
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != NULL || !st.empty())
    {
      while (curr != NULL)
      {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();

      res.push_back(curr->val);
      curr = curr->right;
    }

    return res;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution obj;
  vector<int> res = obj.inorderTraversal(root);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }

  return 0;
}