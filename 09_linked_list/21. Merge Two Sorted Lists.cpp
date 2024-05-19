/*
https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == NULL)
      return list2;

    if (list2 == NULL)
      return list1;

    ListNode *res;

    if (list1->val < list2->val)
    {
      res = list1;
      res->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
      res = list2;
      res->next = mergeTwoLists(list1, list2->next);
    }

    return res;
  }
};

int main()
{
  ListNode *list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(4);
  list1->next->next->next = new ListNode(5);

  ListNode *list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4);

  Solution *obj = new Solution();
  ListNode *res = obj->mergeTwoLists(list1, list2);
  while (res)
  {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;

  return 0;
}