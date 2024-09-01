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
 


ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;  // Initialize the previous pointer as NULL
    ListNode* curr = head;  // Start with the current pointer at the head
    ListNode* fut = NULL;   // Initialize a future pointer to track the next node

    while (curr != NULL) {
        fut = curr->next;   // Store the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move the previous pointer to the current node
        curr = fut;         // Move the current pointer to the next node (future)
    }

    return prev;  // The previous pointer will be the new head of the reversed list
}
};
