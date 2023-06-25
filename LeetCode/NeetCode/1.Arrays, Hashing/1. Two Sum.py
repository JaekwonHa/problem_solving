from typing import List
from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = defaultdict(int)
        for num in nums:
            hash[num] += 1

        for num in nums:
            remain = target - num
            if (remain == num and hash[remain] >= 2) or (remain != num and hash[remain] >= 1):
                answer = []
                for i in range(len(nums)):
                    if nums[i] == num or nums[i] == remain:
                        answer.append(i)
                    if len(answer) == 2:
                        return answer

