# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode()
        dummy.next = head
        first = head
        length = 0
        while first is not None:
            length += 1
            first = first.next

        first = dummy
        length -= n
        for i in range(length):
            first = first.next

        first.next = first.next.next

        return dummy.next
