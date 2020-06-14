from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i, j = 0, 1

        while j < len(nums):
            if nums[i] != nums[j]:
                i, j = j, j +1
                continue
            if nums[i] == nums[j]:
                del nums[j]

        return len(nums)


nums = [0,0,1,1,1,2,2,3,3,4]
solution = Solution()
solution.removeDuplicates(nums)
print(nums)
