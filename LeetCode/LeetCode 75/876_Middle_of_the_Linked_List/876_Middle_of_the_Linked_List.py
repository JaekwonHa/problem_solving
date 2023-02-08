from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        middle, i = head, 0
        while head:
            head = head.next
            i += 1
            if i%2 == 0:
                middle = middle.next
        return middle
        

s = Solution()

print()