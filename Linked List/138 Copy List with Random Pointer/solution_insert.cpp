/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* ptr = head;
        while (ptr) {
            Node* tmp = new Node(ptr->val, nullptr, nullptr);
            tmp->next = ptr->next;
            ptr->next = tmp;
            ptr = ptr->next->next;
        }
        
        ptr = head;
        while (ptr)
        {
            if (ptr->random) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }

        Node* dummy = new Node(-1, nullptr, nullptr);
        Node* currt = dummy;
        ptr = head;
        while (ptr)
        {
            currt->next = ptr->next;
            ptr->next = ptr->next->next;
            currt = currt->next;
            ptr = ptr->next;
        }
        
        return dummy->next;
    }
};