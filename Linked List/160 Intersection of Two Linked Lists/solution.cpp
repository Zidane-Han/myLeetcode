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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        if (!pA || !pB) return NULL;
        
        while (pA != pB) {
            if (!pA && !pB) return NULL;
            else if (!pA && pB) pA = headB;
            else if (!pB && pA) pB = headA;
            else {
                pA = pA->next;
                pB = pB->next;
            }
        }
        
        return pA;
    }
};
