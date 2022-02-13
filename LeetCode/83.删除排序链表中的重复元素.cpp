/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode *cur = head, *nxt = head->next;
        while (nxt->next != nullptr) {
            if (cur->val == nxt->val) {
                cur->next = nxt->next;
            } else {
                cur = nxt;
            }
            nxt = nxt->next;
        }
        if (cur->val == nxt->val) cur->next = nullptr;
        return head;
    }
};
// @lc code=end

