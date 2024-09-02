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
 ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        return merge(l1,l2);

    }
    ListNode *merge(ListNode *h1,ListNode *h2){
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        ListNode *p1=h1;
        ListNode *p2=h2;
        while(p1!=NULL && p2!=NULL){
            if(p1->val>p2->val){
                dummy->next=p2;
                dummy=p2;
                p2=p2->next;
            }
            else{
                dummy->next=p1;
                dummy=p1;
                p1=p1->next;
            }
        } 
        if (p1!=NULL)
            dummy->next=p1;
        if (p2!=NULL)
            dummy->next=p2;
        return temp->next;        
    }
};