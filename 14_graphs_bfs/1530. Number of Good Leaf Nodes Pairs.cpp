/*
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18
*/

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
class Solution {
private:
    void makeGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& leafNodes, TreeNode* prev)
    {
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL)   // leaf nodes
            leafNodes.insert(root);

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, adj, leafNodes, root);
        makeGraph(root->right, adj, leafNodes, root);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leafNodes;

        makeGraph(root, adj, leafNodes, NULL); 


        int count = 0;
        for(auto& leaf : leafNodes)
        {
            // BFS code
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;

            q.push(leaf);
            visited.insert(leaf);

            for(int level=0; level<=distance; level++)
            {
                int size = q.size();
                while(size--)
                {
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr != leaf && leafNodes.count(curr)) {
                        count++;
                    }

                    for(auto& nbr : adj[curr]) {
                       if(!visited.count(nbr)) {
                            q.push(nbr);
                            visited.insert(nbr);
                       }
                    }
                }
            }

        }

        return count / 2;
    }
};
