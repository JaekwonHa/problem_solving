# Definition for a binary tree node.
from queue import Queue


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxDepthDFS(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return 1 + max(self.maxDepthDFS(root.left), self.maxDepthDFS(root.right))

    def maxDepthBFS(self, root: TreeNode) -> int:
        if root is None:
            return 0
        q = Queue()
        res = 0
        q.put(root)
        while q.empty() is False:
            res += 1
            for i in range(0, q.qsize()):
                node = q.get()
                if node.left is not None:
                    q.put(node.left)
                if node.right is not None:
                    q.put(node.right)

        return res


