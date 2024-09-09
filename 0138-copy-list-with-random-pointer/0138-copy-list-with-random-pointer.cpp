/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* headCopy=new Node(0);
//         Node* tailCopy=headCopy;Node* temp=head;
//         while(temp){
//             tailCopy->next=new Node(temp->val);
//             temp=temp->next;
//         }
//         tailCopy=headCopy;
//         headCopy=headCopy->next;
//         delete tailCopy;
        
//         Node* curr1=headCopy,*curr2=head;
//         Node* front1,*front2;
//         while(curr1){
//             front1=curr1->next;
//             front2=curr2->next;
//             curr1->next=curr2;
//             curr2->next=front1;
//             curr1=front1;
//             curr2=front2;
//         }
//         curr1=head;
//         while(curr1){
//             curr2=curr1->next;
//             if(curr1->random){
//                 curr2->random=curr1->random->next;
//                 curr1=curr2->next;
//             }
//         }
//         curr1=head;
//         while(curr1->next){
//             front1=curr1->next;
//             curr1->next=front1->next;
//         }
//             curr1=front1;
//         return headCopy;
//     }
// };


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Copy each node and insert it after the original node
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Step 2: Assign random pointers for the copied nodes
        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node* newHead = head->next;
        Node* original = head;
        Node* copy = newHead;
        
        while (original) {
            original->next = original->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }

        return newHead;
    }
};
