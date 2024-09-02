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
    // ListNode* oddEvenList(ListNode* head) {
    //     ListNode* t=head;
    //     ListNode* s=head->next;
    //     ListNode* p=t;
    //     ListNode* g=s;
    //     while(!s->next->next){
    //         s->next=s->next->next;
    //     }
    //     while(!t->next->next){
    //         t->next=t->next->next;
    //     }
    //     t->next=g;
    //     return p;
    // }
    
    ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head; // Check if the list has less than 2 nodes
    
    ListNode* odd = head;              // Start of the odd-indexed list
    ListNode* even = head->next;       // Start of the even-indexed list
    ListNode* evenHead = even;         // Keep track of the start of the even list
    
    while (even && even->next) {
        odd->next = even->next;        // Link the next odd node
        odd = odd->next;               // Move to the next odd node
        even->next = odd->next;        // Link the next even node
        even = even->next;             // Move to the next even node
    }
    
    odd->next = evenHead;              // Append even list after the odd list
    
    return head;
}

};