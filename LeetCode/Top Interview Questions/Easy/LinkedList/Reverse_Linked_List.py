# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList_iterate(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        while curr is not None:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
        return prev
    def reverseList_recursive(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        p = self.reverseList_recursive(head.next)
        head.next.next = head
        head.next = None
        return p
