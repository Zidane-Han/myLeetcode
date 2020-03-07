// Iterative Way

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
    ListNode* reverseList(ListNode* head) {
        // three pointers
        ListNode* ptr = head;
        ListNode* last = NULL;

        if (ptr == nullptr) return nullptr;

        while (ptr->next != nullptr) {
            ListNode* temp = ptr->next;
            ptr->next = last;
            last = ptr;
            ptr = temp;
        }

        ptr->next = last;

        return ptr;
    }
};