/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode * current = head;
        ListNode * previous = nullptr;
        ListNode *next = nullptr;      // will be used to temporarily store the next node

        while (current != nullptr) {
            next = current->next;      // temporarily store the next node
            current->next = previous;  // reverse the current node
            previous = current;  // before we move to the next node, point previous to the current node
            current = next;      // move on the next node
        }
        // after the loop current will be pointing to 'null' and 'previous' will be the new head
        return previous;
    }
};
// @lc code=end

