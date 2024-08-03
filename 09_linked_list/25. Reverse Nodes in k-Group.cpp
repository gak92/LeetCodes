/*
https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150
*/

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
class Solution {
private:
    int getLength(ListNode* head) {
        int len = 0;

        while(head != NULL) {
            head = head->next;
            len++;
        }

        return len;
    }

    ListNode* reverse(ListNode* head, int& k, int remLen) {
        if(remLen < k)
            return head;

        int count = 0;
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(count < k && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        head->next = reverse(next, k, remLen - count);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);

        return reverse(head, k, len);
    }
};
