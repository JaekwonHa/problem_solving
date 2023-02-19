# Definition for a binary tree node.
import sys
from collections import defaultdict
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


answer = defaultdict(list)


class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        global answer
        answer = defaultdict(list)
        depth = self.dfs(root)

        temp = [[] for _ in range(depth+1)]
        for i in range(depth+1):
            temp[i] = answer[i]

        return temp

    def dfs(self, node):
        global answer

        if node.left is None and node.right is None:
            answer[0].append(node.val)
            return 0

        left = self.dfs(node.left)+1 if node.left is not None else -100
        right = self.dfs(node.right)+1 if node.right is not None else -100
        answer[max(left, right)].append(node.val)
        return max(left, right)


