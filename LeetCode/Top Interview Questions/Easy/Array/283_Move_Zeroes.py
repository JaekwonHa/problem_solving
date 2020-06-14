from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_count = 0
        i = 0
        while i < len(nums):
            if nums[i] == 0:
                del nums[i]
                zero_count += 1
            else:
                i += 1
        [nums.append(0) for _ in range(zero_count)]


