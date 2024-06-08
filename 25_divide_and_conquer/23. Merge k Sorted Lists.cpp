/*
https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
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
  ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;

    if (l1->val < l2->val)
    {
      l1->next = mergeTwoSortedLists(l1->next, l2);
      return l1;
    }
    else
    {
      l2->next = mergeTwoSortedLists(l1, l2->next);
      return l2;
    }

    return NULL;
  }

  ListNode *partitionAndMerge(vector<ListNode *> &lists, int start, int end)
  {
    if (start > end)
      return NULL;
    if (start == end)
      return lists[start];

    int mid = start + (end - start) / 2;

    ListNode *left = partitionAndMerge(lists, start, mid);
    ListNode *right = partitionAndMerge(lists, mid + 1, end);

    return mergeTwoSortedLists(left, right);
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {

    int k = lists.size();

    if (k == 0)
      return NULL;

    return partitionAndMerge(lists, 0, k - 1);
  }
};

int main()
{
  Solution s;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *l3 = new ListNode(7);
  l3->next = new ListNode(8);
  l3->next->next = new ListNode(9);

  vector<ListNode *> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);

  ListNode *res = s.mergeKLists(lists);

  // print res list
  while (res != NULL)
  {
    cout << res->val << " ";
    res = res->next;
  }

  return 0;
}