//https://www.interviewbit.com/problems/list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    // 1->2->3->4->5->6
    //       |        |
    //        - - - - -
    //a: Distance of start of cycle from head of list
    //b: Distance of meeting point from start of cycle
    //c: size of cycle
    //m: no of iterations done by fast
    //n: no of iterations done by slow
    //slow = a + n*c + b
    //fast = a+ m*c +b also equals 2(slow)
    //=> a + m*c + b = 2(a + n*c + b)
    // -(a+b) = c(2*n - m)
    //=> Distance of meeting node from head equals some mutiple of size of cycle
    
    
    ListNode *fast = A;
    ListNode *slow = A;
    bool cycle = false;
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            cycle = true;
            break;
        }
    }
    if(cycle){
        slow = A;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}
