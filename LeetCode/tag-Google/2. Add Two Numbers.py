# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        start = ListNode()
        prev = start
        remain = 0
        while l1 is not None or l2 is not None:
            val1 = l1.val if l1 is not None else 0
            val2 = l2.val if l2 is not None else 0
            temp = (val1 + val2 + remain) % 10
            remain = (val1 + val2 + remain) // 10
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
            current = ListNode(temp)
            prev.next = current
            prev = current
        if remain > 0:
            current = ListNode(remain)
            prev.next = current
            prev = current

        return start.next
