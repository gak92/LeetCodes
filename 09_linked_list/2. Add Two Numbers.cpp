/*
https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int sum = 0;
    int carry = 0;
    ListNode *res = new ListNode();
    ListNode *curr = res;

    while (l1 != NULL || l2 != NULL)
    {
      if (l1)
      {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2)
      {
        sum += l2->val;
        l2 = l2->next;
      }

      int val = sum % 10;
      carry = sum / 10;
      curr->next = new ListNode(val);

      curr = curr->next;
      sum = carry;
    }

    if (carry == 1)
      curr->next = new ListNode(carry);

    return res->next;
  }
};

int main()
{
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  Solution obj;
  ListNode *res = obj.addTwoNumbers(l1, l2);
  while (res != NULL)
  {
    cout << res->val << " ";
    res = res->next;
  }

  return 0;
}