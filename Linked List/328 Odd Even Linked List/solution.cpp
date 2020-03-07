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
    ListNode* oddEvenList(ListNode* head) {
        // use three pointers
        
        if (!head) return head;
        
        ListNode *odd = head; // the tail of odd list 
        ListNode *even_head = head->next; // the head of even list
        ListNode *even_tail = even_head; // pointer to traverse, which is the end of even list
        
        while (true) {
            if (!odd || !even_tail || !even_tail->next) break;
            
            // connect to the odd list
            odd->next = even_tail->next;
            odd = odd->next;
            
            if (!even_tail->next->next) {
                // no more even points
                even_tail->next = even_tail->next->next;
                odd->next = even_head;
                break;
            } else {
                even_tail->next = even_tail->next->next;
                even_tail = even_tail->next;        
                odd->next = even_head;
            }
            
        }
        
        return head;
    }
};