/**
 * Definition for singly-linked list.
 */
 class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val
    this.next = next === undefined ? null : next
  }
}

function mergeTwoLists(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  const nodeArr: ListNode[] = []
  for (let i = l1; i !== null; i = i.next) {
    nodeArr.push(i)
  }
  for (let i = l2; i !== null; i = i.next) {
    nodeArr.push(i)
  }
  nodeArr.sort((a, b) => a.val - b.val)
  for (let i = 0, l = nodeArr.length; i < l; i++) {
    nodeArr[i + 1] && (nodeArr[i].next = nodeArr[i + 1])
  }
  return nodeArr.length ? nodeArr[0] : null
};

function mergeTwoLists2(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  const head = new ListNode()
  let headRef = head
  let _l1 = l1
  let _l2 = l2
  while (_l1 !== null && _l2 !== null) {
    if (_l1.val <= _l2.val) {
      headRef.next = _l1
      _l1 = _l1.next
    } else {
      headRef.next = _l2
      _l2 = _l2.next
    }
    headRef = headRef.next
  }
  headRef.next = _l1 === null ? _l2 : _l1
  return head.next
};
