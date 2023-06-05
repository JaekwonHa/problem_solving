from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # zero_count = 0
        # zero_index = 0
        # for i in range(len(nums)):
        #     if nums[i] == 0:
        #         zero_count += 1
        #         zero_index = i
        #
        # if zero_count > 1:
        #     return [0] * len(nums)
        # if zero_count == 1:
        #     answer = [0 for _ in range(len(nums))]
        #     total = 1
        #     for i in range(len(nums)):
        #         if nums[i] != 0:
        #             total *= nums[i]
        #     answer[zero_index] = total
        #     return answer

        prefix_product = []
        suffix_product = []
        total = 1
        for i in range(len(nums)):
            total *= nums[i]
            prefix_product.append(total)
        total = 1
        for i in range(len(nums)-1, -1, -1):
            total *= nums[i]
            suffix_product.append(total)
        suffix_product.reverse()
        answer = [suffix_product[1]]
        for i in range(1, len(nums)-1):
            answer.append(prefix_product[i-1] * suffix_product[i+1])
        answer.append(prefix_product[-2])
        return answer


