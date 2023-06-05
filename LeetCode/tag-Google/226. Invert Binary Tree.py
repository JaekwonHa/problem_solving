from typing import Optional
import sys
sys.setrecursionlimit(10**6)


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None

        self.dfs(root)
        return root

    def dfs(self, root: Optional[TreeNode]):
        if root is None:
            return
        self.dfs(root.left)
        self.dfs(root.right)

        # root.left, root.right = root.right, root.left

        left = root.left
        root.left = root.right
        root.right = left


