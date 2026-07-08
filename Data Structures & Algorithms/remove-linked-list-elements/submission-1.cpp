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
 //             2 -> 1 -> 4 -> 1 -> 2 -> 3  val = 2
 //dummy        
 //                            curr
 //res -> 1 -> 4
 //
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        ListNode* curr = head;
    

        while(curr)
        {
            if(curr->val != val)
            {
                res->next = curr;
                curr = curr->next;
                res = res->next;
            }
            else
            {
                curr = curr->next;
            }
            res->next = nullptr;
        }

        return dummy->next;
    }
};