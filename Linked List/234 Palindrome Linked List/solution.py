# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if not head or not head.next:
            return True
        
        slow, fast = head, head
        
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        slow = slow.next
        tail = None
        while slow:
            tmp = slow.next
            slow.next = tail
            tail = slow
            slow = tmp
            
        while tail:
            if head.val != tail.val:
                return False
            head = head.next
            tail = tail.next
            
        return True
