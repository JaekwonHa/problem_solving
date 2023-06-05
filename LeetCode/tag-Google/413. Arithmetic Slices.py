from typing import List


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return 0

        answer = 0
        prev = 0
        diff1 = nums[1] - nums[0]
        for i in range(2, len(nums)):
            diff2 = nums[i] - nums[i-1]
            if diff1 != diff2:
                N = i-1 - prev + 1
                answer += max(0, (N-1) * (N-2) // 2)

                diff1 = diff2
                prev = i-1
        N = len(nums)-1 - prev + 1
        answer += max(0, (N-1) * (N-2) // 2)

        return answer

s = Solution()
print(s.numberOfArithmeticSlices([1,2,3,4]))

print(s.numberOfArithmeticSlices([1,2,3,8,9,10]))
