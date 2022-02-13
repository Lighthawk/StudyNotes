/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr || k == 0) return head;

        int listLen = 1;
        ListNode *tail = head, *nxt = head, *cur;
        while (tail->next != nullptr) {
            tail = tail->next;
            listLen ++;
        }

        k = listLen - k % listLen;
        if (k == listLen) return head;
        
        tail->next = head;
        while (k--) {
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = nullptr;
        
        return nxt;
    }
};
// @lc code=end

