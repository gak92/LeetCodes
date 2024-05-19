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

/*



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

      // 1: insert copy node in between
      Node* curr = head;
      while(curr) {
        Node* currNext = curr->next;        // save current ka next

        curr->next = new Node(curr->val);;  // update curr ka next to copy Node
        curr->next->next = currNext;          // update copyNode ka next to curr ka next

        curr = currNext;
      }

      // 2: update random pointer for copy nodes
      curr = head;
      while(curr && curr->next) {
        if(curr->random == NULL) {
            curr->next->random = NULL;
        }
        else {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
      }

      // 3: separate copy list from the original one
      curr = head;
      Node* newHead = head->next;
      Node* newCurr = newHead;

      while(curr && newCurr) {
        curr->next = curr->next == NULL ? NULL : curr->next->next;
        newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;

        curr = curr->next;
        newCurr = newCurr->next;
      }

      return newHead;
    }
};


*/

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