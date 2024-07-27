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
    ListNode* removeElements(ListNode* head, int val) {
        // ListNode* temp=head;
        // ListNode* curr;
        // while(!temp){
        // if(temp->val==val){
        //     curr=temp;
        //     delete curr;
        //     temp=temp->next;
        // }
        // else{
        //     temp=temp->next;
        // }
        // }
        // return head;
        ListNode dummy(0, head);
    ListNode* prev = &dummy;

    for (; head; head = head->next)
      if (head->val != val) {
        prev->next = head;
        prev = prev->next;
      }
    prev->next = nullptr;  // In case that the last value equals `val`.

    return dummy.next;
    }
};