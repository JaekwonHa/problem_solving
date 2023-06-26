from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total = 1
        zeroCount = 0
        for num in nums:
            if num != 0:
                total *= num
            else:
                zeroCount += 1

        if zeroCount >= 2:
            return [0] * len(nums)

        answer = []
        for num in nums:
            if num == 0:
                answer.append(total)
            else:
                answer.append(total // num if zeroCount == 0 else 0)

        return answer
