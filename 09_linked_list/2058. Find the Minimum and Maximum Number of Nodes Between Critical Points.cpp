/*
https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {
    ListNode *prev = head;
    ListNode *curr = head->next;
    int currPos = 1;
    int prevCriticalPos = 0;
    int firstCriticalPos = 0;
    int minDist = INT_MAX;

    while (curr->next != NULL)
    {
      if ((curr->val < prev->val && curr->val < curr->next->val) ||
          (curr->val > prev->val && curr->val > curr->next->val))
      {

        if (prevCriticalPos == 0)
        {
          prevCriticalPos = currPos;
          firstCriticalPos = currPos;
        }
        else
        {
          minDist = min(minDist, currPos - prevCriticalPos);
          prevCriticalPos = currPos;
        }
      }

      currPos++;
      prev = curr;
      curr = curr->next;
    }

    if (minDist == INT_MAX)
      return {-1, -1};

    return {minDist, prevCriticalPos - firstCriticalPos};
  }
};

int main()
{
  ListNode *head = new ListNode(5);
  head->next = new ListNode(3);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next->next = new ListNode(5);

  Solution *sol = new Solution();
  vector<int> res = sol->nodesBetweenCriticalPoints(head);
  cout << res[0] << " " << res[1] << endl;

  return 0;
}