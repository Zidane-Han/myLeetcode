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
    ListNode* plusOne(ListNode* head) {
        // method1: reverse->+1->reverse;
        // method2: recursion;
        // method3: find the first 9 in the list;
        // method4: stack, iteration
        if (!head) return head;
        
        int carry = remainder(head);
        
        if (carry==1) {
            ListNode *num = new ListNode(1);
            num->next = head;
            return num;
        }
        
        return head;
    }
    
    int remainder(ListNode *node) {
        if (!node) return 1;
        
        int carry = remainder(node->next);
        int value = (node->val + carry) / 10;
        node->val = (node->val + carry) % 10;
        
        return value;
    }
    
};