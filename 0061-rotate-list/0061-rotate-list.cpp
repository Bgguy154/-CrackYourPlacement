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
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head)return NULL;
    //     ListNode* curr=head;
    //     int n=1;
    //     while(!curr->next){
    //         curr=curr->next;
    //         n++;
    //     }
    //     ListNode* u=head;
    //     k=k%n;
    //     int j=1;
    //     while(j<n-k){
    //         u=u->next;
    //         j++;
    //     }
    //     u=head;
    //     ListNode* h=u;
    //     while(!u->next){
    //         u=u->next;
    //     }
    //     int l=1;
    //     ListNode* ko=u->next;
    //     while(l<n-k-1){
    //         ko=ko->next;
    //         l++;
    //     }
    //     return h;
    // }
    
    ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head; // Handle empty list or single node case

    // Step 1: Find the length of the linked list
    ListNode* curr = head;
    int n = 1;
    while (curr->next) {  // Traverse to the end of the list to get length
        curr = curr->next;
        n++;
    }

    // Step 2: Make the linked list circular
    curr->next = head;  // Connect the last node to the head

    // Step 3: Calculate the effective number of rotations
    k = k % n;
    int stepsToNewHead = n - k;  // Position of new head

    // Step 4: Move to the new tail (node before the new head)
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 5: Break the circle and set new head
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;  // Break the loop

    return newHead;
}

};