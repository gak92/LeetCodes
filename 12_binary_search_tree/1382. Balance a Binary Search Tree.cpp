/*
https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2024-06-26
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
  void inOrder(TreeNode *root, vector<int> &vec)
  {
    if (root == NULL)
      return;

    inOrder(root->left, vec);
    vec.push_back(root->val);
    inOrder(root->right, vec);
  }
  TreeNode *constructBST(int l, int r, vector<int> &vec)
  {
    if (l > r)
      return NULL;

    int mid = l + (r - l) / 2;

    TreeNode *root = new TreeNode(vec[mid]);
    root->left = constructBST(l, mid - 1, vec);
    root->right = constructBST(mid + 1, r, vec);

    return root;
  }

public:
  TreeNode *balanceBST(TreeNode *root)
  {
    vector<int> vec;
    inOrder(root, vec);

    int l = 0;
    int r = vec.size() - 1;

    return constructBST(l, r, vec);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  root->right->right->right->right = new TreeNode(5);
  root->right->right->right->right->right = new TreeNode(6);
  root->right->right->right->right->right->right = new TreeNode(7);
  root->right->right->right->right->right->right->right = new TreeNode(8);

  Solution obj;
  TreeNode *res = obj.balanceBST(root);
  cout << res->val << endl;

  return 0;
}