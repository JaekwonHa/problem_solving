from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cache = {}
        for i, num in enumerate(nums):
            cache[num] = i
        
        # cache = {nums[i]: i for i in range(0, len(nums))}
            
        for i, one in enumerate(nums):
            two = target - one
            j = cache.get(two)
            if j != None and i != j:
                return [i ,j]


nums = [3,3]
target = 6

s = Solution()

print(s.twoSum(nums, target))
