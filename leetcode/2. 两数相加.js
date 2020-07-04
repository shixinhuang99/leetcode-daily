/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let head = new ListNode(0);
    let cur = head;
    while (l1 || l2) {
        if (l1) {
            cur.val += l1.val;
            l1 = l1.next;
        }
        if (l2) {
            cur.val += l2.val;
            l2 = l2.next;
        }
        if (l1 || l2) {
            cur.next = new ListNode(0);
        }
        if (cur.val >= 10) {
            cur.val -= 10;
            if (cur.next) {
                cur.next.val += 1;
            } else {
                cur.next = new ListNode(1);
            }
        }
        cur = cur.next;
    }
    return head;
};