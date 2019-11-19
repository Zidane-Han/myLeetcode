# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        value = current = ListNode(0)
        temp = 0

        while l1 or l2 or temp:
            if l1:
                temp = temp + l1.val
                l1 = l1.next
            if l2:
                temp = temp + l2.val
                l2 = l2.next

            current.next = ListNode(temp % 10)
            current = current.next
            temp = temp // 10

        return value.next


if __name__ == '__main__':
    # l1 = 2 -> 4 -> 3
    # l2 = 5 -> 6 -> 4
    # result = 7 -> 0 -> 8

    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    result = Solution().addTwoNumbers(l1, l2)
    print(result.val)
    print(result.next.val)
    print(result.next.next.val)