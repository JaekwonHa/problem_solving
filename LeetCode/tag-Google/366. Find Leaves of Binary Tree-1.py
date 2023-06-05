# Definition for a binary tree node.
import sys
from collections import defaultdict
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    q = []

    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.q = []

        answer = []
        while root.left is not None or root.right is not None:
            self.dfs(root)
            answer.append(self.q)
            self.q = []

        answer.append([root.val])
        return answer

    def dfs(self, node: Optional[TreeNode]):
        if node is None:
            return False

        # if (node.left is None or node.left.val in self.visit) and (node.right is None or node.right.val in self.visit):
        if node.left is None and node.right is None:
            self.q.append(node.val)
            return True

        if self.dfs(node.left):
            node.left = None
        if self.dfs(node.right):
            node.right = None

        return False
