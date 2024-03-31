/*
https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
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
  ListNode *oddEvenList(ListNode *head)
  {
    if (head == NULL)
      return head;

    ListNode *odd = head;
    ListNode *oddHead = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    while (even && even->next)
    {
      odd->next = odd->next->next;
      even->next = even->next->next;
      odd = odd->next;
      even = even->next;
    }

    odd->next = evenHead;
    return head;
  }
};
int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  Solution s;
  ListNode *res = s.oddEvenList(head);
  while (res)
  {
    cout << res->val << " ";
    res = res->next;
  }

  return 0;
}