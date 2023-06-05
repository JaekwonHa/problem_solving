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
    layer = defaultdict(list)

    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.layer = defaultdict(list)
        self.dfs(root)
        return self.layer.values()

    def dfs(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0

        left = self.dfs(node.left) + 1
        right = self.dfs(node.right) + 1
        currentLayer = max(left, right)
        self.layer[currentLayer].append(node.val)
        return currentLayer
