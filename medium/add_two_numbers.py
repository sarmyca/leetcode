# Leetcode problem: 2. Add Two Numbers
# Problem link: https://leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # Putting a placeholder node for the result list
        resHead = ListNode(0)
        current = resHead
        carry = 0
        
        # Iterating through both linked lists to the end
        while l1 or l2:
            # Getting the values of the curent nodes (or 0 if none)
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            
            sum = x + y + carry
            
            # Updating the carry
            carry = sum // 10
            
            # Creating the new node with its value being the sum of the current nodes
            current.next = ListNode(sum % 10)
            current = current.next
            
            # If possible move to the next node
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        # If at the end there is a carry -> make a new node with the carry value
        if carry > 0:
            current.next = ListNode(carry)
        
        # The next node after the placeholder is the first node of the result list
        return resHead.next