# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def peek(stack):
    if len(stack) > 0:
        return stack[-1]
    return None

class Solution:

    lca = None
    
    def dfs(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode'):
        if root is None:
            return 0

        left = self.dfs(root.left, p, q)
        right = self.dfs(root.right, p, q)
        
        cur = 0
        if root == p or root == q:
            cur = 1
        if (cur + left + right) == 2 and self.lca is None:
            self.lca = root
        
        return cur + left + right

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # stack = []

        # is_find_p = False
        # is_find_q = False

        # while root is not None and len(stack) > 0:
        #     while root:
        #         if root.right is not None:
        #             stack.append(root.right)
        #         stack.append(root)
        #         root = root.left
        #     root = stack.pop()

        #     if root.right is not None and peek(stack) == root.right:
        #         stack.pop()
        #         stack.append(root)
        #         root = root.right
        #     else:
        #         if root.val == p.val:
        #             is_find_p = True
        #         if root.val == q.val:
        #             is_find_q = True
        #         if is_find_p and is_find_q:
        #             return root
        #         root = None
        # return root

        self.dfs(root, p, q)
        return self.lca




