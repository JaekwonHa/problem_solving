from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left_product = []
        left = 1
        left_product.append(left)
        for i in range(1, len(nums)):
            left *= nums[i-1]
            left_product.append(left)

        right = 1
        for i in range(len(nums)-2, -1, -1):
            right *= nums[i+1]
            left_product[i] *= right

        return left_product


