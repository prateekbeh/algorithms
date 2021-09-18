/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
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
    ListNode *detectCycle(ListNode *head) {
         ListNode * slow = head;
        ListNode * fast = head;
        int cycle_length = 0;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                cycle_length = calc_len(slow);
                break;
            }
        }
        if(cycle_length == 0) return nullptr;
        return findS(head , cycle_length);
    }
    int calc_len(ListNode * slow){
        ListNode * current = slow;
        int len = 0;
        do{
            current = current->next;
            len++;
        }while(current != slow);
        return len;
    }
    ListNode * findS(ListNode * head , int cycle_length){
        ListNode *pointer1 = head, *pointer2 = head;
        // move pointer2 ahead 'cycleLength' nodes
        while (cycle_length > 0) {
            pointer2 = pointer2->next;
            cycle_length--;
        }
        while (pointer1 != pointer2) {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }

        return pointer1;
    }
};
// @lc code=end

