# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Inorder
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        pre = None
        stack = []
        while root is not None or len(stack) != 0:
            while root is not None:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pre is not None and root.val <= pre.val:
                return False
            pre = root
            root = root.right
        return True
