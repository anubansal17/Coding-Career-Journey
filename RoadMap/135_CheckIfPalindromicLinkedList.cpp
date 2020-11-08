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
    bool isPalindrome(ListNode* head) {
        // Finidng the middle of linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Here, slow is pointing to first element in second half
        // Reversing the second half of list
        ListNode* prev = NULL;
        while(slow != NULL) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // 1st ptr pointing to first node of first half
        fast = head;
        // 2nd ptr pointing to first node of second half
        slow = prev;
        while(fast && slow) {
            if(fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
