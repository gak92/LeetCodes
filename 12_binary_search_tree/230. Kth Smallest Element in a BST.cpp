/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150
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
  int kthSmallest(TreeNode *root, int k)
  {
    int n = 0;
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
      n++;
      if (n == k)
        return curr->val;

      curr = curr->right;
    }

    return -1;
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);

  Solution s;
  cout << s.kthSmallest(root, 1) << endl;

  return 0;
}