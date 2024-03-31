/*
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
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
  ListNode *deleteMiddle(ListNode *head)
  {
    if (head->next == NULL)
      return NULL;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = prev->next->next;
    return head;
  }
};

/*
    0   1   2   3   4   5   6   (index)
    1   3   4   7   1   2   6   (values)

            p
                s
                            f

*/

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(3);
  head->next->next = new ListNode(4);
  head->next->next->next = new ListNode(7);
  head->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next = new ListNode(6);

  Solution s;
  ListNode *newHead = s.deleteMiddle(head);
  for (ListNode *cur = newHead; cur != NULL; cur = cur->next)
  {
    cout << cur->val << " ";
  }
  return 0;
}