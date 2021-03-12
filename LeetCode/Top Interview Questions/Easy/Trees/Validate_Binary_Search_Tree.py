from queue import Queue

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        q = Queue()
        if root is not None:
            q.put(root)
        while q.empty() is False:
            node = q.get()
            if node.left is not None:
                if node.left.val < node.val:
                    q.put(node.left)
                else:
                    return False
            if node.right is not None:
                if node.right.val > node.val:
                    q.put(node.right)
                else:
                    return False
        return True
