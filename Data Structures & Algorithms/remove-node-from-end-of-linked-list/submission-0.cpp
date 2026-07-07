/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> nodes;
        ListNode* curr = head;

        while(curr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int index = nodes.size() - n;

        if(index == 0) { return head->next; }

        nodes[index - 1]->next = nodes[index]->next;
        return head;
    }
};
