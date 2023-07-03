from typing import List
from collections import defaultdict

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = []
        nums.sort()

        for i in range(len(nums)-2):
            if i>0 and nums[i-1] == nums[i]:
                continue
            lo, hi = i+1, len(nums)-1
            while lo < hi:
                if nums[lo] + nums[i] + nums[hi] == 0:
                    answer.append([nums[lo], nums[i], nums[hi]])
                    lo += 1
                    hi -= 1
                    while lo < hi and nums[lo] == nums[lo - 1]:
                        lo += 1
                if nums[lo] + nums[i] + nums[hi] > 0:
                    hi -= 1
                if nums[lo] + nums[i] + nums[hi] < 0:
                    lo += 1
        return answer





s = Solution()

nums = [-1,0,1,2,-1,-4]
print(s.threeSum(nums))
