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
        int n = 0;
        ListNode* T = head;
        while (T) {
            n++;
            T = T->next;
        }
        
        int mid = n / 2;
        T = head;
        for (int i = 0; i < mid; i++) {
            T = T->next;
        }
        return T;
    }
};