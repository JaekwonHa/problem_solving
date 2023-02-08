from functools import reduce
from typing import *

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        result = []
        sum = 0
        for num in nums:
            sum += num
            result.append(sum)
        return result


s = Solution()

nums = [1,2,3,4]
print(s.runningSum(nums))
