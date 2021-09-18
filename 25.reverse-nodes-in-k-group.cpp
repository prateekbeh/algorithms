/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {

    if (k <= 1 || head == nullptr) {
      return head;
    }

    ListNode *current = head, *previous = nullptr;
    while (true) {
        ListNode *lastNodeOfPreviousPart = previous;
        
        ListNode *lastNodeOfSubList = current;
        ListNode *next = nullptr;  
        

        ListNode * curr = current;
        for(int i = 1 ; i < k && curr != nullptr; i++){
            curr = curr->next;
        }
        if(curr != nullptr){
            for (int i = 0; current != nullptr && i < k; i++) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            
            // connect with the previous part
            if (lastNodeOfPreviousPart != nullptr) {
                lastNodeOfPreviousPart->next =
                    previous;  // 'previous' is now the first node of the sub-list
            } else {         // this means we are changing the first node (head) of the LinkedList
                head = previous;
            }

            // connect with the next part
            lastNodeOfSubList->next = current;

            if (current == nullptr) {  // break, if we've reached the end of the LinkedList
                break;
            }
            // prepare for the next sub-list
            previous = lastNodeOfSubList;
        }else{
            break;
        }
      }
      

    return head;
  }
};
// @lc code=end

