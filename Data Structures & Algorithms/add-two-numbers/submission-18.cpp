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
//c  
//l1        1 -> 2 -> 3 -> null
//l2        4 -> 5 -> 6 -> null
//dummy     5
//          curr

alignas(ListNode) static unsigned char nodes[128 * sizeof(ListNode)];

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new (nodes) ListNode();
        int carry = 0;

        while(true)
        {
            int val = carry;
            
            if(l1)
            {
                val += l1->val;
                l1 = l1->next;
            }

            if(l2)
            {
                val += l2->val;
                l2 = l2->next;
            }
            
            if(val < 10)
            {
                carry = 0;
            }
            else
            {
                carry = 1;
                val -= 10;
            }

            curr->val = val;
            
            if(l1 || l2 || carry != 0)
            {
                curr->next = new (curr+1) ListNode();
                curr = curr->next;
            }
            else
            {
                break;
            }
        }
        
        return (ListNode*)nodes;
    }
};
