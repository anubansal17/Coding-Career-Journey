//https://www.interviewbit.com/problems/reorder-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    //Split the list in two halves
    //reverse the second half 
    //then merge the elements from two list such that one element from first list and second from second half
    ListNode *slow = A;
    ListNode *fast = A;
    ListNode *pslow = NULL;
    while(fast != NULL and fast->next!= NULL){
        pslow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //If there is only one element in the linked list, in that case
    // We won't ever go into loop, so we shud return the linked list as it is
    if(pslow == NULL){
        return A;
    }
    pslow->next = NULL;
    //Last element of first half shud point to null
    
    ListNode *now = slow;
    ListNode *prev = NULL;
    ListNode *next;
    while(now!=NULL){
        next = now->next;
        now->next = prev;
        prev = now;
        now = next;
    }
    
    ListNode *dummy = new ListNode(0);
    ListNode *dp = dummy;
    ListNode *sp = prev;
    ListNode *fp = A;
    while(sp != NULL and fp != NULL){
        dp->next = fp;
        fp = fp->next;
        
        dp = dp->next;
        dp->next = sp;
        sp = sp->next;
        
        dp = dp->next;
    }
    //To cover the case if the total number of nodes were odd
    if(sp != NULL){
        dp->next = sp;
    }
    return dummy->next;
    
}
