from typing import *

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if (len(nums) == 1):
            return 0

        partial_sum = [0]
        for i in range(len(nums)):
            partial_sum.append(nums[i] + partial_sum[i])
        partial_sum.append(0)

        for i in range(len(nums)):
            if partial_sum[i] == (partial_sum[len(nums)] - partial_sum[i+1]):
                return i
        return -1

s = Solution()
nums = [1,7,3,6,5,6]
print(s.pivotIndex(nums))