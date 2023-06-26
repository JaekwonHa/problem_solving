from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hash = set(nums)

        # answer = 0
        # for num in nums:
        #     local = 1
        #     down = num-1
        #     while down in hash:
        #         local += 1
        #         down -= 1
        #     up = num+1
        #     while up in hash:
        #         local += 1
        #         up += 1
        #     answer = max(answer, local)

        answer = 0
        for num in nums:
            local = 1
            down = num-1
            if down not in hash:
                up = num+1
                while up in hash:
                    local += 1
                    up += 1
                answer = max(answer, local)

        return answer

