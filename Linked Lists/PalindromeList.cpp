//https://www.interviewbit.com/problems/palindrome-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //M1: Using vector
/*int Solution::lPalin(ListNode* A) {
    vector <int> v;
    v.push_back(A->val);
    while(A->next!=NULL){
        A = A->next;
        v.push_back(A->val);
    }
    int n = v.size();
    int l = 0;
    int r = n-1;
    while(l<=r){
        if(v[l]!=v[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
    
}*/
//M2: Using reversing the linked list approach
// find the middle element and then reverse the linked list after middle element 
// compare this part with first part of original linked list
// To find middle element =, we will use fast-slow pointer approach
int Solution::lPalin(ListNode* A) {

    ListNode *slow = A;
    ListNode *fast = A;
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // 1 2 3 4
    //     s   f
    // 1 2 3 4 5
    //     s   f
    // S shud always point to first element of second half in our reqd case
    ListNode *second = slow;
    
    if(fast != NULL){
        second = second->next;
    }
    
    ListNode *prev = NULL;
    ListNode *now = second;
    ListNode *next;
    while(now != NULL){
        next = now->next;
        now->next = prev;
        prev = now;
        now = next;
    }
    
    ListNode *fp = A;
    ListNode *sp = prev;
    while(fp != NULL and sp != NULL){
        if(fp->val != sp->val){
            return 0;
        }
        fp = fp->next;
        sp = sp->next;
    }
    return 1;
    
}
