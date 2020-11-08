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
ListNode* reverse(ListNode* head, int k, int &len) {
        if (len < k) {
            return head;
        }
        int count = 0;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* cur = head;
        while(cur != NULL && count < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        len = len - k;
        // If nodes are still left
        if(next != NULL) {
            // making rest of the list as next of first node
            head->next =  reverse(next, k, len);
        }
        return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // calculating len of list
        int len = 0;
        ListNode* cur = head;
        while(cur != NULL) {
            cur = cur->next;
            len++;
        }
        ListNode* newHead = reverse(head, k, len);
        return newHead;
    }
};
