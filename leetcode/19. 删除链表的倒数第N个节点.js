/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let prehead = new ListNode(0);
    prehead.next = head;
    let f = prehead;
    let s = prehead;
    for (let i = 0; i <= n; ++i) {
        f = f.next;
    }
    while (f) {
        f = f.next;
        s = s.next;
    }
    s.next = s.next.next;
    return prehead.next;
};