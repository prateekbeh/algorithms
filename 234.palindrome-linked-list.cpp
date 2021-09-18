/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != nullptr && fast->next != nullptr){
            
            fast = fast->next->next;
            slow = slow->next;
            
        }
        
        ListNode * second_half_head = reverse(slow);
        ListNode * copysecondhalf = second_half_head;

        while(head != nullptr && second_half_head != nullptr){
            if(head->val != second_half_head->val){
                break;
            }
            head = head->next;
            second_half_head = second_half_head->next;
        }
        reverse(copysecondhalf);
        if (head == nullptr || second_half_head == nullptr) {  // if both halves match
            return true;
        }
        return false;
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

