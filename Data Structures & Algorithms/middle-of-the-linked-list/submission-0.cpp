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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        while(slow)
        {
            res->next = slow;
            slow = slow->next;
            res = res->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};