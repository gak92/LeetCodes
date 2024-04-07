/*
https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
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
  int total = 0;

private:
  void findPathSum(TreeNode *root, int targetSum, long currSum, unordered_map<long, long> prefixSum)
  {
    if (root == NULL)
      return;

    currSum += root->val;
    if (prefixSum.find(currSum - targetSum) != prefixSum.end())
      total += prefixSum[currSum - targetSum];

    prefixSum[currSum]++;
    findPathSum(root->left, targetSum, currSum, prefixSum);
    findPathSum(root->right, targetSum, currSum, prefixSum);
    prefixSum[currSum]--;
    return;
  }
  /*
      // Solution # 01 - O(n^2)
      private:
      void findPathSum(TreeNode* root, int targetSum, long currSum, unordered_map<long, long> prefixSum)
      {
          if(root == NULL)
              return;

          currSum += root->val;
          if(prefixSum.find(currSum - targetSum) != prefixSum.end())
              total += prefixSum[currSum - targetSum];

          prefixSum[currSum]++;
          findPathSum(root->left, targetSum, currSum, prefixSum);
          findPathSum(root->right, targetSum, currSum, prefixSum);
          prefixSum[currSum]--;
          return;
      }

  */
public:
  int pathSum(TreeNode *root, int targetSum)
  {
    // Solution # 02 - O(n)
    if (root == NULL)
      return 0;

    unordered_map<long, long> prefixSum;
    prefixSum[0] = 1;

    findPathSum(root, targetSum, 0, prefixSum);

    return total;

    // Solution # 01 - O(n^2)
    // if(root == NULL)
    //         return 0;

    //     findPathSum(root, targetSum, 0);
    //     pathSum(root->left, targetSum);
    //     pathSum(root->right, targetSum);

    //     return total;
  }
};

int main()
{
  Solution s;
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(-3);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(2);
  root->right->right = new TreeNode(11);
  root->left->left->left = new TreeNode(3);
  root->left->left->right = new TreeNode(-2);
  root->left->right->right = new TreeNode(1);

  int targetSum = 8;
  cout << s.pathSum(root, targetSum) << endl;

  return 0;
}