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
    ListNode* deleteMiddle(ListNode* head) {
        // If there's only one node, return null (empty list)
        if (!head || !head->next) return nullptr;
        
        int count = 0;
        ListNode* temp = head;
        
        // Count the number of nodes in the list
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        // Find the middle node
        count /= 2;
        temp = head;
        
        // Traverse to the node before the middle node
        while (count > 1) {
            temp = temp->next;
            count--;
        }
        
        // Delete the middle node
        ListNode* x = temp->next;
        temp->next = x->next;
        
        // Free the memory of the deleted node if needed
        delete x;
        
        return head;
    }
};
