// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem82.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    const int maxv = 0x3f3f3f3f;
    ListNode* init(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        if (head->next->next == nullptr && head->val == head->next->val) return nullptr;
        else if (head->next->next == nullptr && head->val != head->next->val) return head;
        return head;
    }

    ListNode* remove_head(ListNode *head) {
        head = init(head);
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *pre = head, *cur = head->next;
        int del_flag = 0;
        while (cur != nullptr && pre->val == cur->val) {
            cur = cur->next;
            del_flag = 1;
        }
        if (cur == nullptr || pre->val == cur->val) return nullptr;
        if (del_flag == 0) return init(head);
        else return init(remove_head(cur));            
    }

    ListNode* deleteDuplicates(ListNode* head) {
        head = init(head);
        if (head == nullptr) return nullptr;
        if (head->next == nullptr || head->next->next == nullptr) return init(head);

        int del_flag = 0;
        ListNode *pre, *cur, *nxt;
        head = remove_head(head);
        if (head == nullptr) return nullptr;
        if (head->next == nullptr || head->next->next == nullptr) return init(head);

        pre = head;
        cur = head->next;
        nxt = head->next->next;
        del_flag = 0;
        while (nxt->next != nullptr) {
            if (cur->val == nxt->val) {
                del_flag = 1;
            } else {
                if (del_flag == 1) {
                    pre->next = nxt;
                    del_flag = 0;
                } else {
                    pre = cur;
                }
                cur = nxt;
            }
            nxt = nxt->next;
        }

        if (del_flag == 1) {
            if (cur->val == nxt->val) pre->next = nullptr;
            else pre->next = nxt;
        } else {
            if (cur->val == nxt->val) pre->next = nullptr;
        }
        return head;
    }
};
// @lc code=end

