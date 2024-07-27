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
    bool isPalindrome(ListNode* head) {
//         ListNode* temp=head;
//         int count=0;
//         while(temp){
//             temp=temp->next;
//             count++;
//         }
//         count/=2;
//         ListNode* curr=head,*prev=NULL;
//         while(count--){
//             prev=curr,curr=curr->next;
//         }
//         prev->next=NULL;
        
//         ListNode* front=NULL;
//         prev=NULL;
//         while(curr){
//             front=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=front;
//         }
//         ListNode* head1=head,*head2=prev;
//         while(head1){
//             if(head1->val!=head2->val) return 0;
//             head1=head1->next;
//             head2=head2->next;
//         }
//         return 1;
//         if(head->next==NULL)return 1;
         ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast != nullptr)
      slow = slow->next;
    slow = reverseList(slow);

    while (slow) {
      if (slow->val != head->val)
        return false;
      slow = slow->next;
      head = head->next;
    }

    return true;
  }

 private:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;

    while (head) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
    }
};