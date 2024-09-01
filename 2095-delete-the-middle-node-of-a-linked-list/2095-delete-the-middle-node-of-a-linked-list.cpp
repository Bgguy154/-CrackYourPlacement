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
       if(!head || !head->next)return NULL;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count/=2;
        temp=head;
        while(count>1){
            temp=temp->next;
            count--;
        }
        ListNode* x=temp->next;
        temp->next = x->next;
        delete x;
        return head;
    }
};