from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rangeSumBST(self, node: Optional[TreeNode], low: int, high: int) -> int:
        if node is None:
            return 0

        answer = 0
        # middle
        if low <= node.val <= high:
            answer += node.val
        # left
        answer += self.rangeSumBST(node.left, low, high)
        # right
        answer += self.rangeSumBST(node.right, low, high)

        return answer
