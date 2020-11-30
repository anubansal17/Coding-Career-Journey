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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                break;
            }
        }
        if(fast == NULL || fast->next == NULL) {
            return NULL;
        }
        fast = head;
        //ListNode* prev = slow;
        while(fast != slow) {
            //prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        //prev->next = NULL;
        return slow;
    }
};
