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
        if (!head) return head;
        
        ListNode* result = new ListNode(-1);
        result->next = head;
        
        ListNode* prev = result;
        ListNode* currt;
        
        while (prev) {
            // move currt to a different place
            for (currt = prev->next; currt && prev->next->val == currt->val; currt = currt->next);
            
            if (prev->next && prev->next->next != currt) {
                // delete the middle elements
                while (prev->next != currt) {
                    ListNode* del = prev->next;
                    prev->next = prev->next->next;
                    delete del;
                }
            } else {
                prev = prev->next;
            }
        }
        
        return result->next;
    }
};
