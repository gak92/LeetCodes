/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
  TreeNode *solve(vector<int> &nums, int left, int right)
  {
    if (left > right)
      return NULL;

    int mid = (left + right) / 2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = solve(nums, left, mid - 1);
    root->right = solve(nums, mid + 1, right);

    return root;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    int left = 0;
    int right = nums.size() - 1;

    return solve(nums, left, right);
  }
};

int main()
{
  return 0;
}