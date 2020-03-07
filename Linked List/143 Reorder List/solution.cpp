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
    ListNode* reverse(ListNode* head) {
        ListNode* ptr = head;
        ListNode* last = NULL;
        
        if (!head) return head;
        
        while(ptr->next){
            ListNode* temp = ptr->next;
            ptr->next = last;
            last = ptr;
            ptr = temp;
        }
        
        ptr->next = last;
        return ptr;
    }
    
    void reorderList(ListNode* head) {
        if (!head) return;
        
        ListNode *odd = head;
        ListNode *even = head;
        ListNode *ptr;
        
        while (even && even->next) {
            ptr = odd;
            odd = odd->next;
            even = even->next->next;
        }
        
        if (even) {
            ptr = odd;
            odd = odd->next;
        }
        
        // now ptr point to the end of the first half;
        ptr->next = NULL;
        ListNode *L1 = head;
        ListNode *L2 = reverse(odd);
        ListNode *temp1, *temp2;
        
        while (L2) {
            temp1 = L1->next;
            temp2 = L2->next;
            L1->next = L2;
            L2->next = temp1;
            L1 = temp1;
            L2 = temp2;
        }
        
       
    }
};