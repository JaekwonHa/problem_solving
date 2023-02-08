from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     hash_map = {}
    #     while head:
    #         if head in hash_map:
    #             return hash_map[head]
    #         hash_map[head] = head
    #         head = head.next
    #     return None
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
       
            if slow == fast:
                slow = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow
            
        return None


s = Solution()

print()