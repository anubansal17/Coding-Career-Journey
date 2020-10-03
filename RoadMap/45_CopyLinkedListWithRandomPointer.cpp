// Approach 1: Using Hashing T.C- O(n), S.C - O(n)
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*, RandomListNode*> pointerMap;
    RandomListNode* originalNode = A;
    // Putting nodes into hashmap
    while(originalNode != NULL) {
        RandomListNode* copyNode = new RandomListNode(originalNode->label);
        pointerMap[originalNode] = copyNode;
        originalNode = originalNode->next;
    }
    // Resetting the starting pointer of original LinkedList
    originalNode = A;
    RandomListNode* curCopyNode = NULL;
    // traversing the orginal linkedList to set pointers in copy linkedList
    while(originalNode != NULL) {
        curCopyNode = pointerMap[originalNode];
        curCopyNode->next = pointerMap[originalNode->next];
        curCopyNode->random = pointerMap[originalNode->random];
        originalNode = originalNode->next;
    }
    return pointerMap[A];
}
