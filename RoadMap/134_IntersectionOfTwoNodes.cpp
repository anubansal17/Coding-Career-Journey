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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        while(cur1 != NULL) {
           n1++;
            cur1 = cur1->next;
        }
        while(cur2 != NULL){
            n2++;
            cur2 = cur2->next;
        }
        cur2 = headB;
        cur1 = headA;
        if(n2 > n1) {
            int d =  n2-n1;
            cout<<d;
            while(d != 0) {
                cur2 = cur2->next;
                d --;
            }
        } else {
                int d =  n1-n2;
                while(d != 0) {
                    cur1 = cur1->next;
                    d --;
                }
        }
        while(cur2 != cur1 ) {
                cur2 = cur2->next;
                cur1 = cur1->next;
            }    
        return cur1;
    }
};
