/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan-v2&envId=top-interview-150
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
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;

    ListNode *dummy = new ListNode(-1, head);
    ListNode *curr = head;
    ListNode *prev = dummy;

    while (curr != NULL && curr->next != NULL)
    {
      bool foundDuplicates = false;
      while (curr != NULL && curr->next != NULL && curr->val == curr->next->val)
      {
        curr = curr->next;
        foundDuplicates = true;
      }

      if (foundDuplicates)
        prev->next = curr->next;
      else
        prev = prev->next;

      curr = curr->next;
    }

    return dummy->next;
  }
};

int main()
{
  return 0;
}