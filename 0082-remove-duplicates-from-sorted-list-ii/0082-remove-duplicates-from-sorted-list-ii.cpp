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
        ListNode* T = head;
        ListNode* P = NULL;
        bool trigger = false;
        
        while (T) {
            if (T->next) {
                if (T->val == T->next->val) {
                    trigger = true;
                    T->next = T->next->next;
                } else {
                    if (trigger) {
                        if (P == NULL) {
                            T = T->next;
                            head = T;
                            trigger = false;
                        } else {
                            P->next = T->next;
                            T = T->next;
                            trigger =false;  
                        }
                    } else {
                        P = T;
                        T = T->next;
                    }
                }
            } else {
                if (trigger) {
                    if (P == NULL) {
                        T = T->next;
                        head = T;
                        trigger = false;
                    } else {
                        P->next = T->next;
                        T = T->next;
                        trigger = false;
                    }                      
                } else {
                    P = T;
                    T = T->next;   
                }
            }
        }
        
        return head;
    }
};