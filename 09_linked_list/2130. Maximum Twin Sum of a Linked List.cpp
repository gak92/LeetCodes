/*
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
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
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }

public:
  int pairSum(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *right = reverseList(slow);
    ListNode *left = head;

    int maxi = INT_MIN;
    while (left && right)
    {
      maxi = max(maxi, left->val + right->val);
      left = left->next;
      right = right->next;
    }

    return maxi;
  }
};

int main()
{
  ListNode *head = new ListNode(5);
  head->next = new ListNode(4);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);

  Solution solution;
  cout << solution.pairSum(head) << endl;
  return 0;
}