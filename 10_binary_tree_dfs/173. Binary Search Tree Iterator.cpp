/*
https://leetcode.com/problems/binary-search-tree-iterator/description/?envType=study-plan-v2&envId=top-interview-150
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

class BSTIterator
{
private:
  stack<TreeNode *> st;

public:
  BSTIterator(TreeNode *root)
  {
    TreeNode *curr = root;
    while (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }
  }

  int next()
  {
    TreeNode *res = st.top();
    st.pop();

    TreeNode *curr = res->right;
    while (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }

    return res->val;
  }

  bool hasNext()
  {
    return !st.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator *obj = new BSTIterator(root);
  cout << obj->next() << endl;
  cout << obj->next() << endl;
  cout << obj->hasNext() << endl;
  cout << obj->next() << endl;
  cout << obj->hasNext() << endl;
  cout << obj->next() << endl;
  cout << obj->hasNext() << endl;
  cout << obj->next() << endl;
  cout << obj->hasNext() << endl;
  cout << obj->next() << endl;
  cout << obj->hasNext() << endl;
  cout << obj->next() << endl;
  cout << obj->hasNext() << endl;

  return 0;
}