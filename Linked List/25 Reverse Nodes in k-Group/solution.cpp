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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = slow->next;

        for (int i = 1; fast; i++) {
            if (i%k == 0) {
                slow = reverseOneGroup(slow, fast->next);
                fast = slow->next;
            } else {
                fast = fast->next;
            }
        }

        return dummy->next;
    }

    ListNode* reverseOneGroup(ListNode* pre, ListNode* toConnt) {
        ListNode* last = pre->next;
        ListNode* ptr = last->next;

        while (ptr != toConnt) {
            last->next = ptr->next;
            ptr->next = pre->next;
            pre->next = ptr;
            ptr = last->next;
        }

        return last;
    }

};
