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
        if (head == NULL) return head;
        
        if (head->next) {

            ListNode* A = head;
            ListNode* B = head->next;
            ListNode* C = head->next->next;
            
            A->next = C;
            B->next = A;
            head = B;
            
            ListNode* P = head->next;
            ListNode* curr = head->next->next;
            
            while (curr) {
                if (curr->next != NULL) {
                    
                    ListNode* A = curr;
                    ListNode* B = curr->next;
                    ListNode* C = curr->next->next;
                    
                    P->next = B;
                    B->next = A;
                    A->next = C;
                    
                    P = A;
                    curr = C;
                } else {
                    curr = curr->next;
                }
            }
        }
        
        return head;
    }
};