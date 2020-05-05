from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {nums[i]: i for i in range(0, len(nums))}
        for i in range(len(nums)):
            if hash.get(target - nums[i]) is not None and hash.get(target - nums[i]) != i:
                return [i, hash.get(target - nums[i])]
        return [0, 1]


arr = [0, 4, 3, 0]
solution = Solution();
print(solution.twoSum(arr, 0))
