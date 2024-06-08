/*
https://leetcode.com/problems/sort-list/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
  ListNode *mergeList(ListNode *left, ListNode *right)
  {
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;

    while (left != NULL && right != NULL)
    {
      if (left->val < right->val)
      {
        curr->next = left;
        left = left->next;
      }
      else
      {
        curr->next = right;
        right = right->next;
      }
      curr = curr->next;
    }

    if (left != NULL)
    {
      curr->next = left;
    }
    if (right != NULL)
    {
      curr->next = right;
    }

    return dummy->next;
  }

public:
  ListNode *sortList(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *slow_prev = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow_prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    slow_prev->next = NULL;
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    return mergeList(left, right);
  }
};

int main()
{
  ListNode *head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  Solution s;
  ListNode *res = s.sortList(head);

  // print sorted list
  while (res != NULL)
  {
    cout << res->val << " ";
    res = res->next;
  }

  return 0;
}