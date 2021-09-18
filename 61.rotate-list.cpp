/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int rotations) {
    if (head == nullptr || head->next == nullptr || rotations <= 0) {
      return head;
    }

    // find the length and the last node of the list
    ListNode *lastNode = head;
    int listLength = 1;
    while (lastNode->next != nullptr) {
      lastNode = lastNode->next;
      listLength++;
    }

    lastNode->next = head;    // connect the last node with the head to make it a circular list
    rotations %= listLength;  // no need to do rotations more than the length of the list
    int skipLength = listLength - rotations;
    ListNode *lastNodeOfRotatedList = head;
    for (int i = 0; i < skipLength - 1; i++) {
      lastNodeOfRotatedList = lastNodeOfRotatedList->next;
    }

    // 'lastNodeOfRotatedList.next' is pointing to the sub-list of 'k' ending nodes
    head = lastNodeOfRotatedList->next;
    lastNodeOfRotatedList->next = nullptr;
    return head;
  }
};
// @lc code=end

