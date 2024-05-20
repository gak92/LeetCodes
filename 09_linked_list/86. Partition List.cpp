/*
https://leetcode.com/problems/partition-list/?envType=study-plan-v2&envId=top-interview-150
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
  ListNode *partition(ListNode *head, int x)
  {
    ListNode *left = new ListNode(-1);
    ListNode *right = new ListNode(-1);

    ListNode *leftCurr = left;
    ListNode *rightCurr = right;

    while (head != NULL)
    {
      if (head->val < x)
      {
        leftCurr->next = head;
        leftCurr = leftCurr->next;
      }
      else
      {
        rightCurr->next = head;
        rightCurr = rightCurr->next;
      }
      head = head->next;
    }

    leftCurr->next = right->next;
    rightCurr->next = NULL;

    return left->next;
  }
};

int main()
{
  return 0;
}