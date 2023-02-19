from typing import List


tree = []
treeSize = 0

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        global tree, treeSize
        treeSize = len(nums)
        tree = [-10000 for _ in range(treeSize*2)]
        self.build(nums)

        answer = []
        for i in range(len(nums)-k+1):
            answer.append(self.query(i, i+k))
        return answer

    def build(self, numbers: List[int]):
        global tree, treeSize
        for i in range(treeSize):
            tree[treeSize + i] = numbers[i]

        for i in range(treeSize-1, 0, -1):
            tree[i] = max(tree[i*2], tree[i*2+1])

    def update(self, pos: int, value: int):
        global tree, treeSize

        pos += treeSize
        tree[pos] = value

        while pos > 1:
            pos //= 2
            tree[pos] = max(tree[pos*2], tree[pos*2+1])

    def query(self, left: int, right: int) -> int:
        global tree, treeSize

        res = -10000
        left += treeSize
        right += treeSize
        while left < right:
            if left % 2 == 1:
                res = max(res, tree[left])
                left += 1
            if right % 2 == 1:
                right -= 1
                res = max(res, tree[right])

            left //= 2
            right //= 2
        return res

s = Solution()
input = [1,3,-1,-3,5,3,6,7]
k = 3
print(s.maxSlidingWindow(input, k))
