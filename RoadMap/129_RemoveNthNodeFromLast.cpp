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
// Optimised Approach - Use fast and slow ptr concept
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(NULL);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        // Till count doesn't become equal to n + 1
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
         }
        // Till fast reach at the end
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
            slow->next = slow->next->next;
        return dummy->next;
    }
};
