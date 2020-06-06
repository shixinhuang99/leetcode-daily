/*
 * @Author       : ApassEr
 * @Date         : 2020-06-07 02:07:47
 * @LastEditTime : 2020-06-07 02:10:57
 * @Description  : 19. 删除链表的倒数第N个节点(题解思路)
 * @Algorithm    : 单向链表，双指针
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* f = prehead;
        ListNode* s = prehead;
        for (int i = 0; i <= n; ++i) {
            f = f->next;
        }
        while (f) {
            f = f->next;
            s = s->next;
        }
        ListNode* t = s->next;
        s->next = s->next->next;
        delete t;
        return prehead->next;
    }
};