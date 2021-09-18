/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode * current = head;
        ListNode * previous = nullptr;
        int i = 0;
        while( i < left - 1 && current != nullptr){
            previous = current;
            current = current->next;
            i++;
        }

        ListNode * lastNodeOfFirstPart = previous;
        ListNode * lastNodeOfSubList = current;
        ListNode * next = nullptr;
        
        for(int i = 0 ; current != nullptr && i < right - left + 1 ; i++ ){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        if (lastNodeOfFirstPart != nullptr) {
            lastNodeOfFirstPart->next = previous;  // 'previous' is now the first node of the sub-list
        } else {  // this means p == 1 i.e., we are changing the first node (head) of the LinkedList
            head = previous;
        }
        // connect with the last part
        lastNodeOfSubList->next = current;
        return head; 
    }
};
// @lc code=end

