# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        start = ListNode(0, None)
        curr = start
        p1, p2 = l1, l2
        while p1 is not None and p2 is not None:
            if p1.val < p2.val:
                curr.next = ListNode(p1.val, None)
                p1 = p1.next
            else:
                curr.next = ListNode(p2.val, None)
                p2 = p2.next
            curr = curr.next
        if p1 is not None:
            curr.next = p1
        if p2 is not None:
            curr.next = p2
        return start.next

l1 = ListNode(1, ListNode(2, ListNode(4, None)))
l2 = ListNode(1, ListNode(3, ListNode(4, None)))

solution = Solution()
l3 = solution.mergeTwoLists(l1, l2)

print(l3)
