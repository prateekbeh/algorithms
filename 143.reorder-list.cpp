/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * secondhead = reverse(slow);
        
        ListNode * headfirst = head;
        while(headfirst != nullptr && secondhead != nullptr){
            ListNode * temp = headfirst->next;
            headfirst->next = secondhead;
            headfirst = temp;

            temp = secondhead->next;
            secondhead->next = headfirst;
            secondhead = temp;
        }
        if (headfirst != nullptr) {
            headfirst->next = nullptr;
        }
    }

    ListNode * reverse(ListNode * head){
        ListNode * prev = nullptr;
        while(head != nullptr){
            ListNode * next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
// @lc code=end

