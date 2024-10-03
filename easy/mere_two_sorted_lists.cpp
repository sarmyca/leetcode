// Leetcode problem: 21. Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Creating a placeholder node so that later we can return the head of the merged list
        ListNode resHead;
        ListNode* current = &resHead;

        // Go through both lists untill one of them stops -> attach the smaller node to the merged list
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Then attach the remaining nodes to the merged list
        current->next = (list1 != nullptr) ? list1 : list2;

        // Using the placeholder -> return the head of the merged list
        return resHead.next;
    }
};