from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)

        sortedNums = sorted(nums, key=lambda x: x)

        answer = 1
        answer2 = 1
        for i in range(1, len(sortedNums)):
            # if sortedNums[i-1] == sortedNums[i] or sortedNums[i-1] + 1 == sortedNums[i]:
            if sortedNums[i - 1] + 1 == sortedNums[i]:
                answer2 += 1
            elif sortedNums[i - 1] != sortedNums[i]:
                answer2 = 1
            answer = max(answer, answer2)

        return answer


