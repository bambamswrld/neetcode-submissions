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
        std::unordered_map<Node*, Node*> oldToNew;
        oldToNew[NULL] = NULL;

        Node* curr = head;
        
        while(curr)
        {
            Node* temp = new Node(curr->val);
            oldToNew[curr] = temp;
            curr = curr->next;
        }

        curr = head;

        while(curr)
        {
            Node* temp = oldToNew[curr];
            temp->next = oldToNew[curr->next];
            temp->random = oldToNew[curr->random];
            curr = curr->next;
        }

        return oldToNew[head];
    }
};
