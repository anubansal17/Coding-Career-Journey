// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // base condition
        if(head == NULL) {
            return NULL;
        }
        
        Node* cur = head;
        while(cur != NULL) {
            if(cur->child == NULL){
                cur = cur->next;
            }
            else{
                Node* next = cur->next;
                Node* child = cur->child;
                cur->next = child;
                child->prev = cur;
                cur->child = NULL;
                while(child->next != NULL){
                    child = child->next;
                }
                child->next = next;
                if(next != NULL) {
                    next->prev = child;
                }
            }
        }
    return head;
    }
};
