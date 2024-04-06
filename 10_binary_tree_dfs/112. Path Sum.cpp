/*
https://leetcode.com/problems/path-sum/description/
*/
#include<iostream>
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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private:
    bool dfs(TreeNode* root, int targetSum, int currSum)
    {
        if(!root)
            return false;

        currSum += root->val;
        if(!root->left && !root->right)
            return currSum == targetSum;

        return dfs(root->left, targetSum, currSum) || dfs(root->right, targetSum, currSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int currSum = 0;
        return dfs(root, targetSum, currSum);
    
    }
};

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution s;
    cout<<s.hasPathSum(root, 22)<<endl;
 return 0;
}