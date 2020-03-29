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
        // create new node
        Node* res = new Node(head->val, nullptr, nullptr);
        Node* node = res;
        Node* ptr = head->next;
        unordered_map<Node*, Node*> m;
        m[head] = res;

        while (ptr)
        {
            Node* tmp = new Node(ptr->val, nullptr, nullptr);
            m[ptr] = tmp;
            node->next = tmp;
            ptr = ptr->next;
            node = node->next;
        }
        
        node = res;
        ptr = head;
        while (ptr) {
            node->random = m[ptr->random];
            node = node->next;
            ptr = ptr->next;
        }

        return res;
    }
};