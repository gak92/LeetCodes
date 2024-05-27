/*
https://leetcode.com/problems/clone-graph/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
private:
  unordered_map<Node *, Node *> oldToNew;

  void dfs(Node *node, Node *clone_node)
  {
    for (Node *nbr : node->neighbors)
    {
      if (oldToNew.find(nbr) == oldToNew.end()) // if nbr node not created then created
      {
        Node *clone = new Node(nbr->val);
        oldToNew[nbr] = clone;
        clone_node->neighbors.push_back(clone);
        dfs(nbr, clone);
      }
      else // if nbr node already created
      {
        clone_node->neighbors.push_back(oldToNew[nbr]);
      }
    }
  }

public:
  Node *cloneGraph(Node *node)
  {
    if (node == NULL)
      return NULL;

    oldToNew.clear();

    Node *clone_node = new Node(node->val);
    oldToNew[node] = clone_node;
    dfs(node, clone_node);

    return clone_node;
  }
};

int main()
{
  Solution s;

  Node *node = new Node(1);

  Node *clone_node = s.cloneGraph(node);

  return 0;
}