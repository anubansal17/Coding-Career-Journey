// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        } else if(head->next == NULL){
            return head;
        }
        ListNode* initialHead = head;
        ListNode* head1 = head;
        ListNode* odd = head1;
        ListNode* head2 = NULL;
        head2 = head->next;
        head = head->next;
         
        ListNode* even = head2;
        
        while(head != NULL and head->next != NULL){
            head = head->next;
            odd->next = head;
            odd = odd->next;
            head = head->next;
            even->next = head;
            even = even->next;
        }
        odd->next = head2;
        return head1;
    }
};
