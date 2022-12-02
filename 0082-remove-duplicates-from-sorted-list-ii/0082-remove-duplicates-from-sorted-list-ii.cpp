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
        map<int, int> m;
        ListNode* T = head;
        while (T) {
            m[T->val]++;
            T = T->next;
        }
        head = NULL;
        ListNode* tail = NULL;
        for (auto p : m) {
            if (p.second == 1) {
                ListNode* temp = new ListNode;
                temp->val = p.first;
                if (head == NULL && tail == NULL) {
                    head = temp;
                    tail = temp;
                    head->next = NULL;
                } else {
                    tail->next = temp;
                    temp->next = NULL;
                    tail = temp;
                }
            }
        }
        return head;
    }
};