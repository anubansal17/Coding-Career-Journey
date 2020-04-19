//https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *dummy = new ListNode(0);
    dummy->next = A;
    ListNode *prevPairE = dummy;
    ListNode *curPairS = A;
    while(curPairS != NULL and curPairS->next != NULL){
         ListNode *curPairE = curPairS->next;
         prevPairE->next = curPairE;
         curPairS->next = curPairE->next;
         curPairE->next = curPairS;
         prevPairE = curPairS;
         if(prevPairE != NULL){
             curPairS = curPairS->next;
         }
         
    }
    return dummy->next;
}

