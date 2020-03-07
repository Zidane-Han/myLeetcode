/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        
        if (list1->val <= list2->val) {
            list1->next = this->mergeList(list1->next, list2);
            return list1;
        } else {
            list2->next = this->mergeList(list1, list2->next);
            return list2;
        }
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len==0) {
            return nullptr;
        } else if (len == 1) {
            return lists[0];
        } else if (len == 2) {
            return this->mergeList(lists[0], lists[1]);
        }
        
        
        // shell sort
        vector<ListNode*> listA = {};
        vector<ListNode*> listB = {};
        int mid = len/2;
        
        for (int k = 0; k < len; ++k) {
            if (k <= mid) {
                listA.push_back(lists[k]);
            } else {
                listB.push_back(lists[k]);
            }
        }
        
        ListNode* nodeA = this->mergeKLists(listA);
        ListNode* nodeB = this->mergeKLists(listB);
        
        return this->mergeList(nodeA, nodeB);
    }
};