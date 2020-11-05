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
// T.C- O(max(len(l1), len(l2))), S.C- O(n1+n2)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int sum = 0;
        int carry = 0;
        // Keep running until any of the cond is true
        while(l1 || l2 || carry){
            if(l1) {
              sum += l1->val;
              l1 = l1->next;
            }
            if(l2) {
             sum += l2->val;
             l2 = l2->next; 
            }
            if(carry) {
                sum += carry;
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = temp->next;
            if(sum/10 != 0) {
                carry = 1;
            }
            sum = 0;
        }
        return dummy->next;
    }
};
