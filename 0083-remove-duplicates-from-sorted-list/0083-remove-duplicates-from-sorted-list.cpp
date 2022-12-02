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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* trav = head;
        
        while(trav) {
            if (trav->next) {
                int x = trav->val;
                int y = trav->next->val;                
                if (x == y) {
                    trav->next = trav->next->next;
                } else {
                    trav = trav->next;
                }
            } else trav = trav->next;
        }
        
        return head;
    }
};