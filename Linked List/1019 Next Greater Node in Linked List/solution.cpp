// This is a slow solution

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res = {};
        ListNode* currt = head;
        ListNode* ptr;

        while (currt) {

            ptr = currt->next;
            while (ptr && ptr->val <= currt->val) {
                ptr = ptr->next;
            }

            if (ptr) {
                res.push_back(ptr->val);
            } else {
                res.push_back(0);
            }

            currt = currt->next;
        }

        return res;
    }
};