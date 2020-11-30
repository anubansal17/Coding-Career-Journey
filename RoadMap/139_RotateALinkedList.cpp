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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or k == 0) {
            return head;
        }
        // Finding the last node
        ListNode* cur = head;
        int len = 1;
        while(cur->next != NULL) {
            len++;
            cur = cur->next;
        }
        k %= len;
        // Making next of lst node point to head node
        cur->next = head;
        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;
        // Making next of (k+1)th node point to null
        cur = dummy;
        for (int i = 0; i < len-k; i++) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};
