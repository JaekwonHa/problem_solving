from collections import deque
from typing import List



class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        answer = []

        q = deque([])
        left, right = 0, 0
        while right < len(nums):
            while q and nums[q[-1]] < nums[right]:
                q.pop()
            q.append(right)

            if q[0] < left:
                q.popleft()

            if right-left+1 >= k:
                # res = -10000
                # for i in range(len(q)):
                #     res = max(res, nums[q[i]])
                # answer.append(res)
                answer.append(nums[q[0]])
                left += 1
            right += 1
        return answer

s = Solution()
input = [1,3,-1,-3,5,3,6,7]
k = 3
print(s.maxSlidingWindow(input, k))
