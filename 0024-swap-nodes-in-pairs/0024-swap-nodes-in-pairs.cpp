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
    ListNode* swapPairs(ListNode* head) {
          if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        ListNode* prev = nullptr;
        head = nxt;
        while (curr && nxt) {

            curr->next = nxt->next;
            nxt->next = curr;

            if (prev) {
                prev->next = nxt; 
                // Link the previous pair with the current pair
                // (odd pairs)
            }

            prev = curr;
            curr = curr->next;
            nxt = curr ? curr->next : nullptr;
        }
        return head;
    }
};