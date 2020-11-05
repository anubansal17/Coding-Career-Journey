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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // If l2 is null
        if(l2 == NULL) {
            return l1;
        }
        if(l1 == NULL) {
            return l2;
        }
        
        // Make l1 as smaller list out of two
        if(l1->val > l2->val) {
            std:: swap(l1, l2);
        }
        ListNode* res = l1;
        while(l1 && l2) {
            ListNode* temp = NULL;
            while(l1 && (l1->val <= l2->val)) {
                temp = l1;
                l1 = l1->next;
            }
            // As l2->val is smaller than l1->val
            if(temp){
             temp->next = l2;
            std::swap(l1, l2);   
            }
        }
        return res;
    }
};
