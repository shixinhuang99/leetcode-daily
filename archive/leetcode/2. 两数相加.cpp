/*
 * @Author       : ApassEr
 * @Date         : 2020-06-06 11:57:37
 * @LastEditTime : 2020-06-06 11:59:18
 * @Description  : 2. 两数相加
 * @Algorithm    : 单向链表
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                cur->val += l2->val;
                l2 = l2->next;
            }
            if (l1 != nullptr || l2 != nullptr) {
                cur->next = new ListNode(0);
            }
            if (cur->val >= 10) {
                cur->val -= 10;
                if (cur->next == nullptr) {
                    cur->next = new ListNode(1);
                } else {
                    cur->next->val += 1;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};