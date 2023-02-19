# Definition for a binary tree node.
import sys
from collections import defaultdict
from typing import Optional
sys.setrecursionlimit(10 ** 6)



class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


depth = defaultdict(int)
parent = {}
hash = {}
LCA = None


def levelOrder(root: TreeNode, level):
    global depth, parent, hash
    if root is None:
        return

    depth[root.val] = level
    hash[root.val] = root

    if root.left is not None:
        parent[root.left.val] = root.val
        levelOrder(root.left, level + 1)

    if root.right is not None:
        parent[root.right.val] = root.val
        levelOrder(root.right, level + 1)


def searchLCA(startValue: int, destValue: int):
    global LCA, depth, parent, hash

    node1Value = startValue
    node2Value = destValue

    while depth[node1Value] != depth[node2Value]:
        if depth[node1Value] > depth[node2Value]:
            node1Value = parent[node1Value]
        else:
            node2Value = parent[node2Value]

    while hash[node1Value] != hash[node2Value]:
        node1Value = parent[node1Value]
        node2Value = parent[node2Value]

    LCA = hash[node1Value]


def dfs(root: TreeNode, destValue: int) -> str:
    if root is None:
        return None
    if root.val == destValue:
        return ''

    result = None

    left = dfs(root.left, destValue)
    if left is not None:
        result = 'L' + left
    right = dfs(root.right, destValue)
    if right is not None:
        result = 'R' + right

    return result


class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:

        # make depth
        levelOrder(root, 0)

        # search LCA
        searchLCA(startValue, destValue)

        # dfs
        global LCA
        if LCA is None:
            print(LCA.val)
        upside = dfs(LCA, startValue)
        upside = upside if upside is not None else ''
        downside = dfs(LCA, destValue)
        downside = downside if downside is not None else ''

        return 'U' * len(upside) + downside





