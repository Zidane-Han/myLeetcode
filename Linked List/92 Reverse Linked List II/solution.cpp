/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;

        dummy->next = head;

        for (int i = 0; i < m-1; i++) {
            pre = pre->next;
        }

        ListNode* currt = pre->next;

        for (int i = m; i < n; i++) {
            ListNode* tmp = currt->next;
            currt->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }

        return dummy->next;
    }
};