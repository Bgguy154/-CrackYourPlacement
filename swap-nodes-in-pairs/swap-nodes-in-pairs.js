/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(!head || !head.next)
    return head;
    
    let f=head;
    let s=head.next;
    
    f.next=swapPairs(s.next);
    
    s.next=f;
    
    return s;
};