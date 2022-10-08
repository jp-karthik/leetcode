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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool carry = false;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while (l1 && l2) {
            ListNode * temp = new ListNode();
            if (carry) temp->val = l1->val + l2->val + 1;
            else temp->val = l1->val + l2->val;
            
            if (temp->val / 10) carry = true;
            else carry = false;
            
            temp->val = temp->val % 10;
            
            if (head == NULL) {
                head = temp;
                tail = temp;
                temp->next = NULL;
            } else {
                tail->next = temp;
                temp->next = NULL;
                tail = temp;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            ListNode* temp = new ListNode();

            if (carry) temp->val = l1->val +  1;
            else temp->val = l1->val;

            if (temp->val / 10) carry = true;
            else carry = false;

            temp->val = temp->val % 10;

            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            
            l1 = l1->next;
        }
        
        while (l2) {
            ListNode* temp = new ListNode();

            if (carry) temp->val = l2->val +  1;
            else temp->val = l2->val;

            if (temp->val / 10) carry = true;
            else carry = false;

            temp->val = temp->val % 10;

            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            
            l2 = l2->next;
        }

        if (carry) {
            ListNode* temp = new ListNode();
            temp->val = 1;
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
        }
        
        return head;
    }
};