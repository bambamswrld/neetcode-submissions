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
//            1 -> 2 -> 4 -> null
//            4 -> 5 -> 6 -> null
//  dummmy -> 5    
//  curr   -> curr
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while(l1 || l2 || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int val = val1 + val2 + carry;
            carry = val / 10;
            val = val % 10;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
