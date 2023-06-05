# Definition for a binary tree node.
from typing import List
import sys
sys.setrecursionlimit(10**6)



class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    answer = []

    def dfs(self, root: TreeNode, target: TreeNode, k: int, is_find: bool) -> int:
        if root is None:
            return 0
        if is_find:
            if k == 0:
                self.answer.append(root.val)
            else:
                self.dfs(root.left, target, k - 1, is_find)
                self.dfs(root.right, target, k - 1, is_find)
            return 0

        if root.val == target.val:
            if k == 0:
                self.answer.append(root.val)
            self.dfs(root.left, target, k - 1, True)
            self.dfs(root.right, target, k - 1, True)
            return 1

        depth = self.dfs(root.left, target, k, False)
        if depth > 0:
            if depth == k:
                self.answer.append(root.val)
            self.dfs(root.right, target, k - depth - 1, True)
            return depth + 1

        depth = self.dfs(root.right, target, k, False)
        if depth > 0:
            if depth == k:
                self.answer.append(root.val)
            self.dfs(root.left, target, k - depth - 1, True)
            return depth + 1

        return 0

    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        self.answer = []
        self.dfs(root, target, k, False)
        return self.answer


root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(4)

s = Solution()
print(s.distanceK(root, 5, 2))
