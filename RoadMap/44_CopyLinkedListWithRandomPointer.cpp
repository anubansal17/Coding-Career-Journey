// Approach 1: Using Hashing T.C- O(n), S.C - O(n)
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*, Node*> listMap;
        Node* cur = head;
        while(cur != NULL) {
            Node* newNode = new Node(cur->val);
            listMap.insert({cur, newNode});
            cur = cur->next;
        }
        cur = head;
        while(cur != NULL) {
            listMap[cur]->next = listMap[cur->next];
            listMap[cur]->random = listMap[cur->random];
            cur = cur->next;
        }
        return listMap[head];
    }
};

// Approach 2 : Insering a copy of node between two nodes
// T.C - O(n) and S.C - O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        while(cur != NULL) {
            // Make a copy node
            Node* copyNode = new Node(cur->val);
            // Storing cur->next as backup
            Node* next = cur->next;
            // Making copyNode as cur->next
            cur->next = copyNode;
            // Making copyNode->next point to backup
            copyNode->next = next;
            // Incrementing the pointer to next original node
            cur = cur->next->next;
        }
        cur = head;
        // Traversing the list again, to put random pointers
        while(cur != NULL) {
            if(cur->next) 
                cur->next->random = cur->random ?  
                                 cur->random->next : cur->random;
            cur = cur->next ? cur->next->next: cur->next;
        }
        // Separating the two linkedlists out
        Node* head1 = head;
        Node* head2 = head ? head->next : head;
        Node* temp = head2;
        while(head1 != NULL && temp != NULL) {
            head1->next = head1->next ? head1->next->next : head1->next;
            temp->next = temp->next ? temp->next->next : temp->next;
            temp = temp->next;
            head1 = head1->next;
        }
        return head2;
    }
};
