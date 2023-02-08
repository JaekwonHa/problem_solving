# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        
        result = []
        queue = [root]
        while len(queue) > 0:
            sub_result = []
            node_cnt = len(queue)
            for i in range(node_cnt):
                cur = queue.pop(0)
                if cur.left != None:
                    queue.append(cur.left)
                if cur.right != None:
                    queue.append(cur.right)
                sub_result.append(cur.val)
            result.append(sub_result)

        return result
