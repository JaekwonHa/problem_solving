from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        if list2 is None:
            return list1

        answer = ListNode(0, ListNode())
        cur1, cur2, result = list1, list2, answer

        while cur1 is not None and cur2 is not None:
            if cur1.val <= cur2.val:
                result.next = ListNode(cur1.val)
                cur1, result = cur1.next, result.next
            else:
                result.next = ListNode(cur2.val)
                cur2, result = cur2.next, result.next
        if cur1 is None:
            result.next = cur2
        elif cur2 is None:
            result.next = cur1
        return answer.next
        

s = Solution()

list1 = ListNode(1, ListNode(2, ListNode(4)))
list2 = ListNode(1, ListNode(3, ListNode(4)))

print(s.mergeTwoLists(list1, list2))
