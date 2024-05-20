/*
https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150
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
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == NULL)
      return head;

    int length = 1;
    ListNode *tail = head;

    while (tail->next != NULL)
    {
      tail = tail->next;
      length++;
    }

    k = k % length;
    if (k == 0)
      return head;

    ListNode *curr = head;
    for (int i = 0; i < length - k - 1; i++)
    {
      curr = curr->next;
    }

    ListNode *newHead = curr->next;
    curr->next = NULL;
    tail->next = head;

    return newHead;
  }
};

int main()
{
  return 0;
}