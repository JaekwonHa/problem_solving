from typing import Optional, List
import sys
sys.setrecursionlimit(10**6)

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    answer = []

    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        if root is None:
            return root
        self.answer = []
        self.dfs(root, set(to_delete), True)
        return self.answer

    def dfs(self, root: Optional[TreeNode], to_delete: {}, is_root: bool):
        if root is None:
            return None

        if root.val in to_delete:
            self.dfs(root.left, to_delete, True)
            self.dfs(root.right, to_delete, True)
            return None
        else:
            left = self.dfs(root.left, to_delete, False)
            right = self.dfs(root.right, to_delete, False)

            root.left = left
            root.right = right

            if is_root:
                self.answer.append(root)
            return root
