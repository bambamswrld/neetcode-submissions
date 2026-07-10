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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* curr = head;

        while (true) {
            for (int i = 1; i < m && curr; i++) {
                curr = curr->next;
            }

            if (!curr) {
                break;
            }

            ListNode* scout = curr;

            for (int i = 0; i < n && scout->next; i++) {
                scout = scout->next;
            }

            curr->next = scout->next;
            curr = curr->next;
        }

        return head;
    }
};
