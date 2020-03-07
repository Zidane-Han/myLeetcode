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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        ListNode* temp;
        
        if (!head) return head;
        
        while (ptr->next) {
            if (ptr->val == ptr->next->val) {
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            } else {
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};
