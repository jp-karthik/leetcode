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
    ListNode* swapPairs(ListNode* head) {
        ListNode* T = head;
        while (T) {
            if (T->next) {
                swap(T->val, T->next->val);
                T = T->next->next;
            } else {
                T = T->next;
            }
        }
        return head;
    }
};