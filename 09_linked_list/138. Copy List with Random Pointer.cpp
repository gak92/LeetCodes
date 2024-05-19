/*
https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == NULL)
      return NULL;

    unordered_map<Node *, Node *> mp;

    Node *curr = head;
    Node *prev = NULL;
    Node *newHead = NULL;

    while (curr)
    {
      Node *temp = new Node(curr->val);
      mp[curr] = temp; // storing corresponding new node

      if (newHead == NULL)
      {
        newHead = temp;
        prev = newHead;
      }
      else
      {
        prev->next = temp;
        prev = temp;
      }

      curr = curr->next;
    }

    curr = head;
    Node *newCurr = newHead;
    while (curr)
    {
      if (curr->random == NULL)
      {
        newCurr->random = NULL;
      }
      else
      {
        newCurr->random = mp[curr->random];
      }

      curr = curr->next;
      newCurr = newCurr->next;
    }

    return newHead;
  }
};

int main()
{
  Node *head = new Node(7);
  head->next = new Node(13);
  head->next->next = new Node(11);
  head->next->next->next = new Node(10);
  head->next->next->next->next = new Node(1);

  head->next->random = head;
  head->next->next->random = head->next->next->next->next;
  head->next->next->next->random = head->next;
  head->next->next->next->next->random = head;

  Solution obj;
  Node *newHead = obj.copyRandomList(head);
  Node *curr = newHead;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }

  return 0;
}