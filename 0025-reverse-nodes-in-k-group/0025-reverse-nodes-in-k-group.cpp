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
    ListNode* reverseKGroup(ListNode* head, int k) {
//   next stores the node after curr.
// Update curr->next to skip next and point to next->next (effectively removing next from its original position).
// Insert next at the beginning of the group by updating next->next to point to prev->next.
// Finally, update prev->next to next, effectively placing next as the new head of the reversed group

        
        //           if (!head || k == 1)
//       return head;

//     const int length = getLength(head);
//     ListNode dummy(0, head);
//     ListNode* prev = &dummy;
//     ListNode* curr = head;

//     for (int i = 0; i < length / k; ++i) {
//       for (int j = 0; j < k - 1; ++j) {
//         ListNode* next = curr->next;
//         curr->next = next->next;
//         next->next = prev->next;
//         prev->next = next;
//       }
//       prev = curr;
//       curr = curr->next;
//     }

//     return dummy.next;
//   }

//  private:
//   int getLength(ListNode* head) {
//     int length = 0;
//     for (ListNode* curr = head; curr; curr = curr->next)
//       ++length;
//     return length;
       
//     }
        
        if (!head || k==1)return head;
        const int l=getLength(head);
        ListNode dummy(0,head);
        ListNode* curr=head;
        ListNode*prev=&dummy;
        
        for(int i=0;i<l/k;i++){
            for(int j=0;j<k-1;++j){
                ListNode* next=curr->next;
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
            }
            prev=curr;
            curr=curr->next;
        }
            return dummy.next;
        }
        
        private:
        int getLength(ListNode* head){
            int le=0;
            for(ListNode*curr=head;curr;curr=curr->next)
                ++le;
                return le;
        }
};