/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* current = NULL;
        while (l1 || l2) {
            int val1 = l1 ? l1 -> val : INT_MAX;
            int val2 = l2 ? l2 -> val : INT_MAX;
            ListNode* toAdd;
            if (val1 >= val2) {
                toAdd = l2;
                l2 = l2 ? l2 -> next : NULL;
            } else {
                toAdd = l1;
                l1 = l1 ? l1 -> next : NULL;
            }
            toAdd -> next = NULL;
            if (!head) {
                head = current = toAdd;
            } else {
                current -> next = toAdd;
                current = current -> next;
            }
        }
        return head;
    }
};

// 8ms, 8.9MB