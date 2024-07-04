/*
https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
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

// Solution # 02 (Using Recursion)
/*

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        if(head == NULL)
            return head;

        ListNode* temp = head;
        int sum = 0;

        while(temp != NULL && temp->val != 0)
        {
            sum += temp->val;
            temp = temp->next;
        }

        head->val  = sum;
        head->next = mergeNodes(temp);

        return head;
    }
};

*/

// Solution # 01

class Solution
{
public:
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *p1 = head->next;
    ListNode *p2 = p1;

    while (p2 != NULL)
    {
      int sum = 0;
      while (p2 != NULL && p2->val != 0)
      {
        sum += p2->val;
        p2 = p2->next;
      }

      p1->val = sum;
      p2 = p2->next;
      p1->next = p2;
      p1 = p2;
    }

    return head->next;
  }
};

int main()
{
  ListNode *head = new ListNode(0);
  head->next = new ListNode(3);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(0);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next->next = new ListNode(0);

  return 0;
}