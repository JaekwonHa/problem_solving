from typing import List


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        LIS = []
        DP = [1 for _ in range(len(nums))]

        answer = 0
        LIS.append(nums[0])
        for i in range(1, len(nums)):
            if LIS[-1] < nums[i]:
                LIS.append(nums[i])
                DP[i] = len(LIS)
                answer = max(answer, DP[i])
                continue

            # lower bound
            left, right = 0, len(LIS)-1
            while left <= right:
                mid = (left + right) // 2

                if nums[i] <= LIS[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            LIS[left] = nums[i]
            DP[i] = left
            answer = max(answer, DP[i])

        return True if answer >= 3 else False
        # return answer

s = Solution()
# nums = [1,2,3,4,5]
# print(s.increasingTriplet(nums))
#
# nums = [5,4,3,2,1]
# print(s.increasingTriplet(nums))

nums = [2,1,5,0,4,6]
print(s.increasingTriplet(nums))

nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
print(s.increasingTriplet(nums))

